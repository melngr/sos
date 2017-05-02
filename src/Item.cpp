#include <string>
#include "Item.h"
#include <algorithm>

//generate a new Item
Item::Item(std::string name, int maxuses) : Usable(name, maxuses) {}

Item::~Item() {
}

//only use Item if has available uses
int Item::use(int consumed) {
	int returnVal = consumed + std::min(_uses-consumed,0);
	_uses = std::max(_uses-consumed,0);
	return returnVal;
}

//toss an Item
void Item::discard() {
	delete(this);
}
