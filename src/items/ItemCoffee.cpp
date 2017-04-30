#include <string>
#include "Item.h"
#include "ItemCoffee.h"

ItemCoffee::ItemCoffee(std::string name, int maxuses) : Item(name, maxuses) {
	_name = "Coffee with " + name;
}

ItemCoffee::~ItemCoffee() {
}

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