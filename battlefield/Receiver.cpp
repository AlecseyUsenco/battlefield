#include "Receiver.h"


MyReceiver::MyReceiver(SAppContext& Context) : Context(Context)
{
	for (u32 i = 0; i<100; i++)
	{
		KeyIsDown[i] = false;
	}
	Mouse = false;
}

bool MyReceiver::OnEvent(const SEvent& event)
{
	if (event.EventType == EET_KEY_INPUT_EVENT)
	{
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		return false;
	}

	if(event.EventType == EET_MOUSE_INPUT_EVENT)
	{
		infoText += stringw(L"X: ");
		infoText += stringw(event.MouseInput.X);
		infoText += stringw(L"\n");

		infoText += stringw(L"Y: ");
		infoText += stringw(event.MouseInput.Y);
		infoText += stringw(L"\n");

		Context.InfoStatic->setText(infoText.c_str());

		/*if (event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN)
		{
		}*/
	}

	if (event.EventType == EET_GUI_EVENT)
	{
		s32 id = event.GUIEvent.Caller->getID();
		switch (event.GUIEvent.EventType)
		{
		case EGET_BUTTON_CLICKED:
			switch (id)
			{
			case GUI_ID_SKILL4:
				Skill_4 = true;
				return true;
				break;
			case GUI_ID_SKILL2:
				return true;
				break;
			case GUI_ID_SKILL3:
				return true;
				break;
			case GUI_ID_SKILL1:
				return true;
				break;
			default:
				return false;
			}
			break;
		default:
			break;
		}
	}
	return false;
}

bool MyReceiver::IsKeyDown(EKEY_CODE keyCode)
{
	return KeyIsDown[keyCode];
}

MyReceiver::~MyReceiver()
{
}
