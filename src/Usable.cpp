/*
 * Usable.cpp
 *
 * adds the constructor, Usable.use and Usable.discard vary
 * for Item, use and discard change the uses and either affect the player or not
 * for Skill, use activates the skill and discard deletes the skill
 */

#include <string>
 #include <iostream>

#include "Usable.h"

Usable::Usable(std::string name, int maxuses) {
	_name = name;
	_uses = maxuses;
	_maxuses = maxuses;
}

Usable::~Usable() {
}

std::string Usable::getName() {	return _name; }
int Usable::getUses() { return _uses; }
int Usable::getMaxuses() { return _maxuses; }

void Usable::updateName(std::string name) {	_name = name; }

std::ostream& operator<<(std::ostream& ostr, const Usable& u){
	//ostr << "PRINTING A " << u.getClassType(ostr) << ":" << std::endl;
	ostr << u._name;
}