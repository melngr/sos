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