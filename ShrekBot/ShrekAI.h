#ifndef SHREKAI_H
#define SHREKAI_H
class ShrekAI {
public:
	void farmCS();
	void attack();
	void attackEnemy();
	void attackMinion();
	void followPlayer();
	void buyItems(int item);
	bool isLow();
	bool dead();
	bool isTurret1Alive();
	bool isTurret2Alive();
	bool isTurret3Alive();
	bool checkColorOn(int x, int y, int cR, int cG, int cB);
};


#endif TITLEMANAGER_H
