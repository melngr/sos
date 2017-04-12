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
	Player(std::string name);

	void useSkill(int index);
	void useItem(int index);

private:
	//std::vector<Skill> _skills
	//std::vector<Item> _items
};

#endif