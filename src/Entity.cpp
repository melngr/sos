/*
 * Entity.cpp
 *
 * not much implementation because Entity is simple
 * more specific functions in Player and Monster
 */

#include <string>

#include "Entity.h"

Entity::Entity() {
	_name = "new Entity";
	_stamina = 0;
	_attack = 0;
	_defense = 0;
}

std::string Entity::getName() {	return _name; }
int Entity::getStamina() { return _stamina; }
int Entity::getAttack() { return _attack; }
int Entity::getDefense() { return _defense; }

void Entity::updateName(std::string name) { _name = name; }
void Entity::updateStamina(int stam) { _stamina = stam; }
void Entity::updateAttack(int atk) { _attack = atk; }
void Entity::updateDefense(int def) { _defense = def; }