#pragma once
#include<irrlicht.h>
#include<irrbullet.h>
#include<iostream>

using namespace irr;
using namespace core;
using namespace video;
using namespace gui;
using namespace std;

enum
{
	GUI_ID_SKILL1,
	GUI_ID_SKILL2,
	GUI_ID_SKILL3,
	GUI_ID_SKILL4,
};

struct SAppContext
{
	IGUIStaticText *InfoStatic;
};

class MyReceiver : public IEventReceiver
{
public:
	SAppContext &Context;
	bool Skill_4;
	bool Mouse;
	stringw infoText; 
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	virtual bool OnEvent(const SEvent& event);
	virtual bool IsKeyDown(EKEY_CODE keyCode);
	MyReceiver(SAppContext& Context);
	~MyReceiver();
};

