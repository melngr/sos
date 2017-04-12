/*
 * Monster.cpp
 *
 * provides Monster constructor
 * Monsters do attacks too but at a reduced amount compared to Player
 */

#include <string>

#include "Monster.h"

Monster::Monster(std::string name) : Entity() {
	_name = name;
}

int Monster::useSkill(int index) {
	return 0;
}