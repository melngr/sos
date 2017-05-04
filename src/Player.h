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
#include "Item.h"

class Player : public Entity {
public:
	//give the player a name
	Player(std::string name);
	~Player();

	std::string getClassType(std::ostream& ostr) const { 
		return "Player"; 
	}; //return classname as str
	std::string getNonBasicInfo(std::ostream& ost) const; //returns anything specific to a given class as a string used in operator<<
	int numSkills() {return (int)_skills.size(); };
	//use Skill or Item from members
	int useSkill(int index);
	int useItem(int index);
	int skillIndex(std::string skillName);

	void learnSkill(std::string newSkill, int maxUses){
		_skills.push_back(new Skill(newSkill, maxUses));
	}

private:
	//Skill and Item stored in a vector
	std::vector<Skill*> _equippedSkills;
	std::vector<Skill*> _skills;
	std::vector<Item*> _items;
	//hack something together, iterative function, recursive function, refactor generally, dynamic programming, linear programming
	//sleep on it!, google, play solitaire, browse youtube, write black box tests (gives a bonus if used early?), white box testing (late fight)
	//video games (rarely a good idea but inspiration can strike), dfs, bfs, djikstras
};

#endif