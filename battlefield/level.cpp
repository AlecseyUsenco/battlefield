#include"level.h"

void level::create()
{
	ISceneNode *Node = device->getSceneManager()->addCubeSceneNode(1.0);
	Node->setScale(vector3df(300, 3, 300)); // 400, 3, 400
	Node->setPosition(vector3df(20, 0, 10));
	Node->setMaterialFlag(video::EMF_LIGHTING, false);
	Node->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, false);
	Node->setMaterialTexture(0, device->getVideoDriver()->getTexture("../models/rockwall.jpg"));
	Node->setMaterialFlag(EMF_WIREFRAME, false);
	ICollisionShape *shape = new IBoxShape(Node, 0, false);
	IRigidBody *body;
	body = world->addRigidBody(shape);
}

void level::Skill()
{
		IAnimatedMesh *mesh = smgr->getMesh("../models/dwarf.x");
		Dwarf = smgr->addAnimatedMeshSceneNode(mesh);
		Dwarf->setScale(vector3df(0.2, 0.2, 0.2));
		Dwarf->setMaterialFlag(EMF_LIGHTING, false);
		Dwarf->setPosition(vector3df(0, 40, 100));
		ICollisionShape *shape = new IBvhTriangleMeshShape(Dwarf, mesh, 1000.0);
		Dwarff = world->addRigidBody(shape);
		Dwarff->setActivationState(EAS_DISABLE_DEACTIVATION);
		Dwarff->setDamping(-0.4, -0.4);
}

void level::RunLevel()
{
	bool start = true;
	device = createDevice(EDT_DIRECT3D9, dimension2d<u32>(640, 480), 16, false, false, false, 0);
	smgr = device->getSceneManager();
	driver = smgr->getVideoDriver();
	gui = smgr->getGUIEnvironment();
	world = createIrrBulletWorld(device, true, true);
	world->setGravity(vector3df(0, -10, 0));
	create();
	//Skill();
	u32 TimeStamp = device->getTimer()->getTime();
	u32 DeltaTime = 0;

	ITexture *ImageSkill1 = driver->getTexture("../models/1.jpg");
	ITexture *ImageSkill2 = driver->getTexture("../models/2.jpg");
	ITexture *ImageSkill3 = driver->getTexture("../models/3.png");
	ITexture *ImageSkill4 = driver->getTexture("../models/4.png");

	spriteBank = gui->addEmptySpriteBank("cursor");
	s32 i = spriteBank->addTextureAsSprite(driver->getTexture("../models/icon_crosshairs16x16bw1.png"));
	SCursorSprite cursorSpraite(spriteBank, i);

	MyReceiver receiver(context_game);
	InfoStatic = context_game.InfoStatic;

	device->setEventReceiver(&receiver);

	smgr->addCameraSceneNode(0, vector3df(0, 50, 230), vector3df(0, 10, 10));

	while (device->run())
	{
		DeltaTime = device->getTimer()->getTime() - TimeStamp;
		TimeStamp = device->getTimer()->getTime();
		driver->beginScene(true, true, SColor(255, 100, 101, 140));
		world->stepSimulation(DeltaTime*0.001f, 120);
		world->debugDrawWorld(true);
		world->debugDrawProperties(false);

		if (receiver.Skill_4 == true)
		{
			Skill1->setVisible(false);
			Skill2->setVisible(false);
			Skill3->setVisible(false);
			Skill4->setVisible(false);
			device->getCursorControl()->setActiveIcon(device->getCursorControl()->addIcon(cursorSpraite));
			Skill();
			receiver.Skill_4 = false;
			receiver.Mouse = false;
		}

		if (receiver.Mouse == true && receiver.Skill_4 == false)
		{
			Skill1->setVisible(true);
			Skill2->setVisible(true);
			Skill3->setVisible(true);
			Skill4->setVisible(true);
			SCursorSprite cursorSpraite2(spriteBank, 1);
			device->getCursorControl()->setActiveIcon(device->getCursorControl()->addIcon(cursorSpraite2));
			receiver.Mouse = false;
		}

		if (start == true)
		{
			Skill1 = gui->addButton(rect<s32>(550, 100, 595, 145), 0, GUI_ID_SKILL1);
			Skill1->setImage(ImageSkill1);
			Skill2 = gui->addButton(rect<s32>(600, 100, 645, 145), 0, GUI_ID_SKILL2);
			Skill2->setImage(ImageSkill2);
			Skill3 = gui->addButton(rect<s32>(650, 100, 695, 145), 0, GUI_ID_SKILL3);
			Skill3->setImage(ImageSkill3);
			Skill4 = gui->addButton(rect<s32>(700, 100, 745, 145), 0, GUI_ID_SKILL4);
			Skill4->setImage(ImageSkill4);
			start = false;
		}
		gui->drawAll();
		smgr->drawAll();
		driver->endScene();
	}
}

level::level()
{
}

level::~level()
{}