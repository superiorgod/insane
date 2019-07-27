#include "WindowManager.h"
#include <Windows.h>
#include <iostream>

bool WindowManager::clientExists() {

	HWND hWnd = FindWindowA(0, ("League of Legends"));

	if (hWnd != NULL) {
		return true;
	}
	else {
		return false;
	}

}

bool WindowManager::gameExists() {

	HWND hWnd = FindWindowA(0, ("League of Legends (TM) Client"));

	if (hWnd != NULL) {
		return true;
	}
	else {
		return false;
	}

}