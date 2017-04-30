#include <string>
#include "Item.h"

//generate a new Item
Item::Item(std::string name, int maxuses) : Usable(name, maxuses) {}

Item::~Item() {
}

//only use Item if has available uses
int Item::use(int consumed) {
	if (consumed > _uses) {
		_uses -= consumed;
		return consumed;
	}
	else
	{
		_uses = 0;
		return _uses;
	}
}

//toss an Item
void Item::discard() {
	delete(this);
}
