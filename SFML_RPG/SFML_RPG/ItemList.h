#ifndef ITEMLIST_H
#define ITEMLIST_H

#define NUM_OF_ITEMS 3

#include "Item.h"

class ItemList {
	public:
		ItemList();
		~ItemList();
		static Item &returnRandomItem();
	private:
		static Item AllItems[NUM_OF_ITEMS];
		static Item coin ;
		static Item healthPotion;
		static Item jewel;
};

#endif // ITEMLIST_H
