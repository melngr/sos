/*
 * Monster.h
 *
 * represents opponents found in dungeons
 * have Skill like the Player but cant use Items
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include <iostream>

#include "Entity.h"
#include "Skill.h"


class Monster : public  Entity {
public:
	//give the Monster a name
	Monster(std::string name);
	~Monster();

	std::string getClassType(std::ostream& ostr) const {
		return "monster"; 
	}; //return classname as str
	std::string getNonBasicInfo(std::ostream& ostr) const { 
		return "good luck defeating me!";
	}; //returns anything specific to a given class as a string used in operator<<


	//use Skill
	int useSkill(int index);
	int useItem(int index);

	void setStats(int att, int def, int hp){
		_attack = att;
		_defense = def;
		_stamina = hp;
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Monster& m); 
private:
	//Monster only has Skill vector
	std::vector<Skill> _skills;
};

#endif