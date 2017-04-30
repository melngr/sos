/**
Parent class for other items
Inherits Usable traits from that class and adds a self destroy when _uses runs out
*/

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Usable.h"

class Item : public Usable {
public:
	Item(std::string name, int maxuses);
	~Item();

	virtual int use(int consumed);
	void discard();
};

#endif
