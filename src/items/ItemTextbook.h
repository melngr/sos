#ifndef ITEMBOOK_H
#define ITEMBOOK_H

#include <string>
#include "Item.h"

class ItemTextbook : Item {
public:
	ItemTextbook(std::string name, int maxuses);
	~ItemTextbook();

	int use(int consumed);
};

#endif