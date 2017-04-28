#include <string>
#include "Item.h"

Item::Item(std::string name, int maxuses) : Usable(name, maxuses) {}

Item::~Item() {
}

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

void Item::discard() {
	delete(this);
}