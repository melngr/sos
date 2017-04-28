/*
 * Monster.h
 *
 * represents opponents found in dungeons
 * have Skill like the Player but cant use Items
 */

#ifndef GENERIC_CODING_MONSTER_H
#define GENERIC_CODING_MONSTER_H

#include <string>
#include <vector>
#include <iostream>

#include "Entity.h"
#include "Monster.h"
#include "Skill.h"


class GenCodeMonster : public  Entity, public Monster {
public:
	//give the Monster a name
	GenCodeMonster(std::string name);
	~GenCodeMonster();

	std::string getClassType(std::ostream& ostr) const {
		return "GenCodeMonster"; 
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

private:
	//Monster only has Skill vector
	std::vector<Skill> _skills;
	
};

#endif