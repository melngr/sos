/*
 * Monster.cpp
 *
 * provides Monster constructor
 * Monsters do attacks too but at a reduced amount compared to Player
 */

#include <string>

#include "Monster.h"

Monster::Monster(std::string name) : Entity(name) {
}

Monster::~Monster() {
}

int Monster::useSkill(int index) {
	return 0;
}

int Monster::useItem(int index) {
	return 0;
}

std::ostream& operator<<(std::ostream& ostr, const Monster& m){
	ostr << "Printing a monster: " <<std::endl;
	ostr << "Rawr! I am a " << m._name << std::endl;
	ostr << "HP: " << m._stamina << "\tATT: " << m._attack << std::endl;
	ostr << "Good Luck defeating me" << std::endl;
	ostr << "done printing the monster!" << std::endl;
	return ostr;
}