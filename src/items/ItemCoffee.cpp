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
	if (_uses - consumed > 0) {
		_uses -= consumed;
		int boost = (5 * consumed);
		return boost;
	}
	else {
		int boost = (5 * _uses);
		_uses = 0;
		return boost;
	}
}
