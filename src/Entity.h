/*
 * Entity.h
 *
 * class file to define characters and monsters
 * some common attributes as well
 * Player and Monster will have other unique features tied to them
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
	//constructors
	Entity();

	//accessors for debugging/calculations elsewhere
	std::string getName();
	int getStamina();
	int getAttack();
	int getDefense();

	//mutators for updates
	void updateName(std::string name);
	void updateStamina(int stam);
	void updateAttack(int atk);
	void updateDefense(int def);

private:
	std::string _name;
	int _stamina;
	int _attack;
	int _defense;
};

#endif