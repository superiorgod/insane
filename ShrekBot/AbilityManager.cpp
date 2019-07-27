#include <windows.h>
#include "AbilityManager.h"
#include "UtilManager.h"
#include <iostream>

UtilManager UM;

WORD ability_Q = 0x10; // 0x10 //0x22 = G 23 = H 24 J = 25 = K
WORD ability_W = 0x11;
WORD ability_E = 0x12;
WORD ability_R = 0x13;

WORD upgrade_Q = 0x22; // G
WORD upgrade_W = 0x23; // H
WORD upgrade_E = 0x24; // J
WORD upgrade_R = 0x25; // K

WORD ability_D = 0x20;
WORD ability_F = 0x21;

WORD ability_B = 0x30;
WORD ability_P = 0x19;
WORD ability_Y = 0x15;

WORD ability_T = 0x14;

using namespace std;

void AbilityManager::upgradeAbility(char ability, bool random) {
	WORD fixedAbility = toupper(ability);
	if (random) {
		fixedAbility = UM.randomAbility();
	}
	switch (fixedAbility) {
	case 'Q':
		fixedAbility = upgrade_Q;
		cout << "Q UPGR" << endl;
		break;
	case 'W':
		fixedAbility = upgrade_W;
		cout << "W UPGR" << endl;
		break;
	case 'E':
		fixedAbility = upgrade_E;
		cout << "E UPGR" << endl;
		break;
	case 'R':
		fixedAbility = upgrade_R;
		cout << "R UPGR" << endl;
		break;
	default:
		break;
	}

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = fixedAbility; //0x82 num1, 83 num2 - skillu upgradinimui
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = fixedAbility;
	ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	Sleep((rand() % 20 + 1));

	// RELEASE ABILITY KEY
	ip.ki.wVk = fixedAbility;
	ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
	SendInput(1, &ip, sizeof(INPUT));
}

	void AbilityManager::castAbility(char ability, bool random) {
		WORD fixedAbility = toupper(ability);
		if (random) {
			fixedAbility = UM.randomAbility();
		}
		switch (fixedAbility) {
		case 'Q':
			fixedAbility = ability_Q;
			break;
		case 'W':
			fixedAbility = ability_W;
			break;
		case 'E':
			fixedAbility = ability_E;
			break;
		case 'R':
			fixedAbility = ability_R;
			break;
		case 'D':
			fixedAbility = ability_D;
			break;
		case 'F':
			fixedAbility = ability_F;
			break;
		case 'P':
			fixedAbility = ability_P;
			break;
		case 'Y':
			fixedAbility = ability_Y;
			break;
		case 'B':
			fixedAbility = ability_B;
			break;
		case 'T':
			fixedAbility = ability_T;
			break;
		default:
			break;
		}
		// 0x65 = SHIFT+F2=F14
		// 0x240 = f6
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = fixedAbility; //0x82 num1, 83 num2 - skillu upgradinimui T - F2
		ip.ki.time = 0; 
		ip.ki.dwExtraInfo = 0;
		ip.ki.wVk = fixedAbility;
		ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		Sleep(60 + (rand() % 30 + 1));

		// RELEASE ABILITY KEY
		ip.ki.wVk = fixedAbility;
		ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
		SendInput(1, &ip, sizeof(INPUT));
	}

	void AbilityManager::castAbilityOn(char ability, int x, int y, bool random) {
		SetCursorPos(x, y);
		Sleep(1);

		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

		Sleep(5);
		WORD fixedAbility = toupper(ability);
		if (random) {
			fixedAbility = UM.randomAbility();
		}
		switch (fixedAbility) {
		case 'Q':
			fixedAbility = ability_Q;
			break;
		case 'W':
			fixedAbility = ability_W;
			break;
		case 'E':
			fixedAbility = ability_E;
			break;
		case 'R':
			fixedAbility = ability_R;
			break;
		case 'D':
			fixedAbility = ability_D;
			break;
		case 'F':
			fixedAbility = ability_F;
			break;
		default:
			break;
		}

		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = fixedAbility;
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;
		ip.ki.wVk = fixedAbility;
		ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		Sleep((rand() % 20 + 1));

		// RELEASE ABILITY KEY
		ip.ki.wVk = fixedAbility;
		ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
		SendInput(1, &ip, sizeof(INPUT));
	}
	

	void AbilityManager::mouseMove(int x, int y)
	{
		double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
		double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
		double fx = x * (65535.0f / fScreenWidth);
		double fy = y * (65535.0f / fScreenHeight);
		INPUT Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_MOVE;
		Input.mi.dx = fx;
		Input.mi.dy = fy;
		::SendInput(1, &Input, sizeof(INPUT));
	}

	void AbilityManager::recall() {
		castAbility(ability_B);
	}

	void AbilityManager::lockCamera() {
		castAbility(ability_Y);
	}

	void AbilityManager::openShop() {
		castAbility(ability_P);
	}

	void AbilityManager::goToPlayer() {
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = ability_T; //0x82 num1, 83 num2 - skillu upgradinimui
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;
		ip.ki.wVk = ability_T;
		ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));


		Sleep(10);

		SetCursorPos(800, 440);
		Sleep(1);

		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

		// RELEASE ABILITY KEY
		ip.ki.wVk = ability_T;
		ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE;
		SendInput(1, &ip, sizeof(INPUT));
	}