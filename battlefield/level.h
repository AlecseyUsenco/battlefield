#include<irrlicht.h>
#include<iostream>
#include<irrbullet.h>
#include"Receiver.h"

using namespace std;
using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace gui;
using namespace scene;

class level
{
public:
	IrrlichtDevice *device;
	ISceneManager *smgr;
	IVideoDriver *driver;
	IGUIEnvironment *gui;
	irrBulletWorld *world;
	ICameraSceneNode *camera;
	ISceneNode *Dwarf;
	IRigidBody *Dwarff;
	SAppContext context_game;

	IGUIButton *Skill1, *Skill2, *Skill3, *Skill4;
	IGUISpriteBank* spriteBank;
	IGUIStaticText *InfoStatic;

	void Skill();
	void create();
	void RunLevel();
	level::level();
	level::~level();
};