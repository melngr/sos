/*
 * Entity.cpp
 *
 * not much implementation because Entity is simple
 * more specific functions in Player and Monster
 */

#include <string>
#include <iostream>

#include "Player.h"
#include "Monster.h"
#include "Entity.h"

Entity::Entity(std::string name) {
	_name = name;
	_stamina = 0;
	_attack = 0;
	_defense = 0;
}

Entity::~Entity() {
}

std::string Entity::getName() {	return _name; }
int Entity::getStamina() { return _stamina; }
int Entity::getAttack() { return _attack; }
int Entity::getDefense() { return _defense; }

std::string Entity::getClassType(std::ostream& ostr) const{ return "Entity";}
std::string Entity::getNonBasicInfo(std::ostream& ostr) const { return "I simply exist";}

void Entity::updateName(std::string name) { _name = name; }
void Entity::updateStamina(int stam) { _stamina = stam; }
void Entity::updateAttack(int atk) { _attack = atk; }
void Entity::updateDefense(int def) { _defense = def; }

std::ostream& operator<<(std::ostream& ostr, const Entity& e){
	ostr << std::endl << std::endl;
	ostr << "Printing a " << e.getClassType(ostr) << ": " <<std::endl;
	ostr << "Rawr! I am a " << e._name << std::endl;
	ostr << "HP: " << e._stamina << "\tATT: " << e._attack << std::endl;
	ostr << e.getNonBasicInfo(ostr) << std::endl;
	ostr << "done printing the " << e.getClassType(ostr) << "!" << std::endl;
	return ostr;
}
