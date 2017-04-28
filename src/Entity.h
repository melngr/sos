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
	Entity(std::string name);
	virtual ~Entity();

	//accessors for debugging/calculations elsewhere, returns the attribute in the name
	std::string getName();  
	int getStamina();
	int getAttack();
	int getDefense();
	virtual std::string getClassType(std::ostream& ostr) const; //return classname as str
	virtual std::string getNonBasicInfo(std::ostream& ostr) const; //returns anything specific to a given class as a string used in operator<<

	//mutators for updates, modifes the given attribute to be equal to the passed param
	void updateName(std::string name);
	void updateStamina(int stam);
	void updateAttack(int atk);
	void updateDefense(int def);

	//use Skill or Item
	virtual int useSkill(int index) = 0;
	virtual int useItem(int index) = 0;

	friend std::ostream& operator<<(std::ostream& ostr, const Entity& e);

protected:
	//members of both Monster and Player
	std::string _name;
	int _stamina;
	int _attack;
	int _defense;

};

#endif