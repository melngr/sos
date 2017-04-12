/*
 * Usable.cpp
 *
 * adds the constructor, Usable.use and Usable.discard vary
 * for Item, use and discard change the uses and either affect the player or not
 * for Skill, use activates the skill and discard deletes the skill
 */

#include <string>

#include "Usable.h"

Usable::Usable() {
	_name = "new Usable";
	_uses = 0;
	_maxuses = 0;
}

int Usable::use(int inputval) {
	return 0;
}

void Usable::discard() {
	return;
}