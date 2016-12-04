#ifndef NPC_H
#define NPC_H

#include "Creature.h"
#include <string>

class NPC : public Creature
{
public:
	NPC::NPC(std::string file, std::string name, std::string intersectionText, int location, int AI_ID, Vector2f startingPosition, std::vector<RectangleShape> &obstacles);
	~NPC();
	void updateNPC();
	void setIntersectionText(std::string intText);
	std::string getIntersectionText();

	//AI Paths for NPC's
	
	void onPlayerBulletIntersect();
	void onPlayerIntersect();
	void onEnemyBulletIntersect();

private:
	bool alive;
	Clock directionClock;
	Time directionTime;
	std::string intText;//intersection text
};

#endif // !NPC_H
