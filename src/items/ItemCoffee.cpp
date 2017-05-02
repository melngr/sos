#include <string>
#include "Item.h"
#include "ItemCoffee.h"

//make a coffee
ItemCoffee::ItemCoffee(std::string name, int maxuses) : Item(name, maxuses) {
	_name = "Coffee with " + name;
}

ItemCoffee::~ItemCoffee() {
}

/**
gives 5 * the number of coffees consumed as an attack boost
the boost is applied via Player function
*/
int ItemCoffee::use(int consumed) {
	return Item::use(consumed) * 5;
}
