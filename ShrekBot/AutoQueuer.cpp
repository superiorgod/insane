#include <Windows.h>
#include "AutoQueuer.h"
#include "WindowManager.h"
#include "TitleManager.h"
#include <list>
#include <iostream>
#include <string>
/*
play: 280, 110
coops vs ai: 310, 170
intro: 500, 570
begginer: 510, 600
intermediate: 510, 630
confirm/find match: 690, 760
accept: 800, 630
champ1: 550, 240
champ2: 650, 240
champ3: 750, 240
champ4: 850, 240
champ5: 950, 240
*/

WindowManager WM;
TitleManager TM;


void AutoQueuer::mouseLClick(int x, int y) {

	SetCursorPos(x, y);
	Sleep(1);

	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void AutoQueuer::mouseRClick(int x, int y) {

	SetCursorPos(x, y);
	Sleep(1);

	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}



void AutoQueuer::startGame(int difficulty) {

	if (WM.gameExists()) {
		std::cout << "[!] ALREADY IN GAME" << std::endl;
		return;
	}

	bool ingame = false;
	int count = 0;
	TM.queueTitle();
	ingame = false;
	Sleep(5000);
	mouseLClick(280, 110); // CLICKS PLAY
	Sleep(200);
	mouseLClick(310, 170); // COOPS VS AI
	Sleep(200);
	mouseLClick(500, 570); // BEGGINER
	Sleep(200);
	mouseLClick(690, 760); // CONFIRM
	Sleep(200);
	mouseLClick(690, 760); // FIND MATCH
	while (!ingame) {
		if (count >= 6) {
			count = 0;
		}
		count += 1;
		Sleep(3000);
		mouseLClick(800, 630);
		Sleep(5000);
		switch (count) {
		case 1:
			mouseLClick(550, 240);
			break;
		case 2:
			mouseLClick(650, 240);
			break;
		case 3:
			mouseLClick(750, 240);
			break;
		case 4:
			mouseLClick(850, 240);
			break;
		case 5:
			mouseLClick(950, 240);
			break;
		default:
			break;
		}
	}
}