#include "ShrekAI.h"
#include "AutoQueuer.h"
#include "AbilityManager.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <tuple>

using namespace std;
AutoQueuer AQ;
AbilityManager AM;
ShrekAI AI;

extern bool recalling = false;

int item1_x = 450;
int item1_y = 240;

int item2_x = 500;
int item2_y = 240;

int item3_x = 550;
int item3_y = 240;

int item4_x = 450;
int item4_y = 340;

int item5_x = 500;
int item5_y = 340;

int item6_x = 500;
int item6_y = 340;

int turret1_x = 1195;
int turret1_y = 735; // 48 133 159 or 53 147 177

int turret2_x = 1185;
int turret2_y = 755; // 51 137 170

int turret3_x = 1165;
int turret3_y = 770; // 50 137 165

bool ShrekAI::checkColorOn(int x, int y, int Cr, int Cg, int Cb) {

	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	HWND hDesktopWnd = GetDesktopWindow();
	HDC hDesktopDC = GetDC(hDesktopWnd);
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, nScreenWidth, nScreenHeight);
	SelectObject(hCaptureDC, hCaptureBitmap);

	BitBlt(hCaptureDC, 0, 0, nScreenWidth, nScreenHeight, hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = nScreenWidth;
	bmi.bmiHeader.biHeight = nScreenHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	RGBQUAD *pPixels = new RGBQUAD[nScreenWidth * nScreenHeight];

	GetDIBits(
		hCaptureDC,
		hCaptureBitmap,
		0,
		nScreenHeight,
		pPixels,
		&bmi,
		DIB_RGB_COLORS
	);

	// write:
	int p;

	p = (nScreenHeight - x - 1)*nScreenWidth + y; // upside down
	unsigned char r = pPixels[p].rgbRed;
	unsigned char g = pPixels[p].rgbGreen;
	unsigned char b = pPixels[p].rgbBlue;

	if (r == Cr && g == Cg && b == Cb) {
		return true;
	}
	else {
		return false;
	}


	delete[] pPixels;

	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);
}

bool ShrekAI::dead() {
	if (AI.checkColorOn(802, 672, 1, 13, 7)) {
		return true;
	}
	else {
		return false;
	}
}

void ShrekAI::buyItems(int item) {
	AM.openShop();
	Sleep((rand() % 50 + 1));
	switch (item) {
	case 1:
		AQ.mouseRClick(item1_x, item1_y);
		break;
	case 2:
		AQ.mouseRClick(item1_x, item1_y);
		break;
	case 3:
		AQ.mouseRClick(item1_x, item1_y);
		break;
	case 4:
		AQ.mouseRClick(item1_x, item1_y);
		break;
	case 5:
		AQ.mouseRClick(item1_x, item1_y);
		break;
	case 6:
		AQ.mouseRClick(item1_x, item1_y);
		break;
	default:
		break;
	}
	Sleep((rand() % 50 + 1));
	AM.openShop();
}

void ShrekAI::attack() {
	if (recalling) {
		return;
	}
	bool attackedChamp = false;
	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	HWND hDesktopWnd = GetDesktopWindow();
	HDC hDesktopDC = GetDC(hDesktopWnd);
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, nScreenWidth, nScreenHeight);
	SelectObject(hCaptureDC, hCaptureBitmap);

	BitBlt(hCaptureDC, 0, 0, nScreenWidth, nScreenHeight, hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = nScreenWidth;
	bmi.bmiHeader.biHeight = nScreenHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	RGBQUAD *pPixels = new RGBQUAD[nScreenWidth * nScreenHeight];

	GetDIBits(
		hCaptureDC,
		hCaptureBitmap,
		0,
		nScreenHeight,
		pPixels,
		&bmi,
		DIB_RGB_COLORS
	);

	// write:
	int p;
	int x, y;
	for (y = 0; y < nScreenHeight; y++) {
		for (x = 0; x < nScreenWidth; x++) {
			p = (nScreenHeight - y - 1)*nScreenWidth + x; // upside downe
			unsigned char r = pPixels[p].rgbRed;
			unsigned char g = pPixels[p].rgbGreen;
			unsigned char b = pPixels[p].rgbBlue;

			if (r == 203 && g == 110 && b == 104) { // enemy healthbar color
				attackedChamp = true;
				AM.castAbilityOn('Q', x, y + 64, true);
				AM.castAbility('D');
				AM.castAbility('F');
				//	cout << "naudoja ability" << endl;
				break;
			}


		}
	}
	if (!(attackedChamp)) {
		for (y = 0; y < nScreenHeight; y++) {
			for (x = 0; x < nScreenWidth; x++) {
				p = (nScreenHeight - y - 1)*nScreenWidth + x; //
				unsigned char r = pPixels[p].rgbRed;
				unsigned char g = pPixels[p].rgbGreen;
				unsigned char b = pPixels[p].rgbBlue;

				if (r == 197 && g == 89 && b == 89) { // enemy minion healthbar color
					//champOnScreen = true;
					AM.castAbilityOn('Q', x + 27, y + 30, true);
					break;
				}


			}
		}
	}

	delete[] pPixels;

	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);

	return;
}


bool ShrekAI::isLow() {

	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	HWND hDesktopWnd = GetDesktopWindow();
	HDC hDesktopDC = GetDC(hDesktopWnd);
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, nScreenWidth, nScreenHeight);
	SelectObject(hCaptureDC, hCaptureBitmap);

	BitBlt(hCaptureDC, 0, 0, nScreenWidth, nScreenHeight, hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = nScreenWidth;
	bmi.bmiHeader.biHeight = nScreenHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	RGBQUAD *pPixels = new RGBQUAD[nScreenWidth * nScreenHeight];

	GetDIBits(
		hCaptureDC,
		hCaptureBitmap,
		0,
		nScreenHeight,
		pPixels,
		&bmi,
		DIB_RGB_COLORS
	);

	// write:
	int p;
	int x, y;

	p = (nScreenHeight - 870 - 1)*nScreenWidth + 740; // upside down
	unsigned char r = pPixels[p].rgbRed;
	unsigned char g = pPixels[p].rgbGreen;
	unsigned char b = pPixels[p].rgbBlue;

	if (r == 1 && g == 13 && b == 7) {
		recalling = true;
		AM.recall();
		Sleep(15000);
	}
	AI.buyItems((rand() % 3) + 1);
	recalling = false;
	delete[] pPixels;

	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);

	return false;
}

bool isTurret1Alive() {
	if ( (AI.checkColorOn(turret1_x, turret1_y, 48, 133, 159) || (AI.checkColorOn(turret1_x, turret1_y, 53, 147, 177) ))) {
		return true;
	}
	else {
		return false;
	}
}

bool isTurret2Alive() {
	if (AI.checkColorOn(turret2_x, turret2_y, 51, 137, 170)) {
		return true;
	} 
	else {
		return false;
	}
}

bool isTurret3Alive() {
	if (AI.checkColorOn(turret3_x, turret3_y, 50, 137, 165)) {
		return true;
	}
	else {
		return false;
	}
}

void ShrekAI::followPlayer() {
	
	AM.castAbility('T');
	AQ.mouseRClick(740, 425);
} 