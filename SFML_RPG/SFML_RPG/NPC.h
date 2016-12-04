#ifndef NPC_H
#define NPC_H

#include "Creature.h"
#include <string>

class NPC : public Creature
{
public:
	NPC::NPC(std::string file, std::string name, int location, int AI_ID, Vector2f startingPosition, std::vector<RectangleShape> &obstacles);
	~NPC();
	void updateNPC();
	void drawText();

	//AI Paths for NPC's
	void selectAI(int aID);
	void ai1(); //Stand still.
	void ai2(); //Move like monsters.
	void ai3(); //
	void ai4();
	void ai5();
	void ai6();
	void ai7();
	void onPlayerBulletIntersect();
	void onPlayerIntersect();
	void onEnemyBulletIntersect();

private:
	std::vector<RectangleShape> currentObstacles;
	void setRandomDirection();
	bool alive;
	Clock directionClock;
	Time directionTime;
	int aID;
};

#endif // !NPC_H
