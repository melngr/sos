#include <string>
#include "Item.h"
#include <algorithm>

//generate a new Item
Item::Item(std::string name, int maxuses) : Usable(name, maxuses) {}

Item::~Item() {
}

//only use Item if has available uses
int Item::use(int consumed) {
	int used = std::min(_uses,consumed);
	_uses -= used;
	return used;
}

//toss an Item
void Item::discard() {
	delete(this);
}
