#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Entity.h"

class Item : public Entity
{
	public:
		Item();
		Item(std::string filename, Vector2f imageSize, int id, std::string name, int value);
		~Item();
		int getID();
		std::string getName();
		int getValue();

		void setID(int i);
		void setName(std::string s);
		void setValue(int v);

	private:
		int ID;
		std::string name;
		int value;


};
#endif // !ITEM_H
