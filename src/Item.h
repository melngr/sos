#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Usable.h"

class Item : Usable {
public:
	Item(std::string name, int maxuses);
	~Item();

	virtual int use(int consumed);
	void discard();
};

#endif