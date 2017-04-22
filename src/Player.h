/*
 * Player.h
 *
 * Player class to represent the user
 * Inherits from Entity to have stats and name
 * Adds specifics for using Skill and Item objects
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

#include "Entity.h"
#include "Skill.h"
#include "Usable.h"

class Player : public Entity {
public:
	//give the player a name
	Player(std::string name);
	~Player();

	std::string getClassType(std::ostream& ostr) const { 
		return "Player"; 
	}; //return classname as str
	std::string getNonBasicInfo(std::ostream& ost) const; //returns anything specific to a given class as a string used in operator<<

	//use Skill or Item from members
	int useSkill(int index);
	int useItem(int index);
	//friend std::ostream& operator<<(std::ostream& ostr, const Player& player);

private:
	//Skill and Item stored in a vector
	std::vector<Skill*> _equippedSkills;
	std::vector<Skill*> _skills;
	//std::vector<Item*> _items;
};

#endif