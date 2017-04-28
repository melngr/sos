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

//Usable class; handles basic attributes of any Usable sub-objects (currently name, #uses, and max #uses)
Usable::Usable(std::string name, int maxuses) {
	_name = name;
	_uses = maxuses;
	_maxuses = maxuses;
}

//virtual Usable destructor; to be implemented by children
Usable::~Usable() {
}

//public Usable getters
std::string Usable::getName() {	return _name; }
int Usable::getUses() { return _uses; }
int Usable::getMaxuses() { return _maxuses; }

//public Usable setters
void Usable::updateName(std::string name) {	_name = name; }

//Usable toString -- output the current object's name and #uses
std::ostream& operator<<(std::ostream& ostr, const Usable& u){
	//ostr << "PRINTING A " << u.getClassType(ostr) << ":" << std::endl;
	ostr << u._name;
	return ostr;
}