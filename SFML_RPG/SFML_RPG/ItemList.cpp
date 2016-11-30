#include "ItemList.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Make items like this in this format
Item ItemList::coin = *new Item("res/Items/coin.png", Vector2f(17, 17), 1, "Coins", 1);
Item ItemList::healthPotion = *new Item("res/Items/healthPotion.png", Vector2f(15, 21), 2, "Health Potion", 10);
Item ItemList::jewel = *new Item("res/Items/jewel.png", Vector2f(15, 17), 3, "Jewel", 50);

//Add items to list here.
Item ItemList::AllItems[NUM_OF_ITEMS] = { coin, healthPotion, jewel };

ItemList::ItemList() {

}
ItemList::~ItemList() {

}
Item & ItemList::returnRandomItem() {
	srand(time(NULL));
	int ran = rand() % NUM_OF_ITEMS;
	return AllItems[ran];
}