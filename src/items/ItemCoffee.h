/**
Coffee Item
Child of Item which is one of the Usable class
When consumed adds some attack to the Player
*/

#ifndef ITEMCOFFEE_H
#define ITEMCOFFEE_H

#include <string>
#include "Item.h"

class ItemCoffee : Item {
public:
	ItemCoffee(std::string name, int maxuses);
	~ItemCoffee();

	int use(int consumed);
};

#endif
