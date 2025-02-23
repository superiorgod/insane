#include <iostream>
#include <ctime>
#include <Windows.h>
#include "AbilityManager.h"
#include "UtilManager.h"
#include "WindowManager.h"
#include "AutoQueuer.h"
#include "ShrekAI.h"
#include <chrono>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>
#include <d3d9.h>
using namespace std;



int main()
{

	srand(time(NULL));
	AbilityManager AM;
	UtilManager UM;
	WindowManager WM;
	AutoQueuer AQ;
	ShrekAI AI;
	Sleep(5000);
	AM.lockCamera();
	AM.castAbility('Q', false);
	AI.buyItems(1);
	AI.buyItems(2);
	int counter = 0;
	while (true) {
		if (counter == 6) {
			AM.upgradeAbility('Q', true);
			AI.followPlayer();
			counter = 0;
		}
		//	AI.isLow();
			AI.attack();
			if (AI.dead()) {
				AI.buyItems(4);
				Sleep(60 + (rand() % 30 + 1));
				AI.buyItems(5);
				Sleep(60 + (rand() % 30 + 1));
				AI.buyItems(1);
				Sleep(60 + (rand() % 30 + 1));
		}
		Sleep(1000);
		counter += 1;
	}  

	return 0;
}
