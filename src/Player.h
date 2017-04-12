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

#include "Entity.h"

class Player : public Entity {
public:
	//give the player a name
	Player(std::string name);

	//use Skill or Item from members
	int useSkill(int index);
	int useItem(int index);

private:
	//Skill and Item stored in a vector
	//std::vector<Skill> _skills
	//std::vector<Item> _items
};

#endif