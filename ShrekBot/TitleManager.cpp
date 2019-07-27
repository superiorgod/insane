#include <Windows.h>
#include <string>
#include "TitleManager.h"
#include <iostream>


void TitleManager::queueTitle() {

	SetConsoleTitle(L"[SHREKB0T] SEARCHING FOR GAME");

}

void TitleManager::gameTitle() {

	SetConsoleTitle(L"[SHREKB0T] IN GAME");

}