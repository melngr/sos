#include <string>
#include "Item.h"
#include "ItemTextbook.h"

ItemTextbook::ItemTextbook(std::string name, int maxuses) : Item(name, maxuses) {
	_name = "Textbook on: " + name;
}

ItemTextbook::~ItemTextbook() {
}

int ItemTextbook::use(int consumed) {
	if (_uses - consumed > 0) {
		_uses -= consumed;
		int boost = (10 * consumed);
		return boost;
	}
	else {
		int boost = (10 * _uses);
		_uses = 0;
		return boost;
	}
}