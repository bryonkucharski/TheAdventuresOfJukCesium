#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity
{
	public:
		Projectile(std::string file, Vector2f size, Vector2f pos, int dir, int speed);
		~Projectile();
		void setActive(bool state);
		void update();
		void setDirection(int d);
		void setSpeed(float s);
		void setAnimationCounter(int a);

		float getOffSetX();
		float getOffSetY();

		void setOffSetX(float offX);
		void setOffSetY(float offY);

		
		int getDirection();
		int getSpeed();
		bool isActive();
		int getAnimationCounter();

		void onCollision();
		
	private:
		void updateAnimation();
		bool active;
		int speed;
		int direction;

		float animationCounter;
		Clock clock,animationClock;
		Time time, animationTime;
		float offsetX;
		float offsetY;
		
};

#endif // !PROJECTILE_H
