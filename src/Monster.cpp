/*
 * Monster.cpp
 *
 * provides Monster constructor
 * Monsters do attacks too but at a reduced amount compared to Player
 */

#include <string>

#include "Monster.h"

//Monster class; stores the generic Entity attributes as well as attributes unique to monsters
Monster::Monster(std::string name) : Entity(name) {
}

//delete any data that the Monster class put on the heap (currently nothing to delete)
Monster::~Monster() {
}

//use the skill at input index 
int Monster::useSkill(int index) {
	return 0;
}

//use the item at input index
int Monster::useItem(int index) {
	return 0;
}

//Monster toString -- output current attributes
std::ostream& operator<<(std::ostream& ostr, const Monster& m){
	ostr << "Printing a monster: " << std::endl;
	ostr << "Rawr! I am a " << m._name << std::endl;
	ostr << "HP: " << m._stamina << "\tATT: " << m._attack << std::endl;
	ostr << "Good Luck defeating me" << std::endl;
	ostr << "done printing the monster!" << std::endl;
	return ostr;
}