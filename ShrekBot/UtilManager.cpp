#include "UtilManager.h"
#include <cstdlib>

char UtilManager::randomLetter() {

	char x = 'A' + rand() % 26;

	return x;
}

char UtilManager::randomAbility() {

	char abilities[3] = { 'Q', 'W', 'E' };
	int i = rand() % 3;

	return abilities[i];
}

int UtilManager::randomNumber(int min, int max) {

	int number = min + (rand() % static_cast<int>(max - min + 1));

	return number;
}