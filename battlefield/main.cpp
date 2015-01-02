#include<iostream>
#include<irrlicht.h>
#include<irrbullet.h>
#include"level.h"

using namespace std;
using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace gui;
using namespace scene;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrBullet.lib")
#pragma comment(lib, "BulletDynamics.lib")
#pragma comment(lib, "BulletSoftBody.lib")
#pragma comment(lib, "LinearMath.lib")
#pragma comment(lib, "BulletMultiThreaded.lib")
#pragma comment(lib, "BulletCollision.lib")
#endif

int main()
{
	level NewLevel;
	NewLevel.RunLevel();
}