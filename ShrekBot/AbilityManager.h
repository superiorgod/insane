#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

class AbilityManager {
	public:
		void upgradeAbility(char ability, bool random = false);
		void castAbility(char ability, bool random = false);
		void castAbilityOn(char ability, int x, int y, bool random = false);
		void mouseMove(int x, int y);
		void lockCamera();
		void openShop();
		void recall();
		void goToPlayer();
};

#endif ABILITYMANAGER_H