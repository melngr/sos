/*
 * Monster.h
 *
 * represents opponents found in dungeons
 * have Skill like the Player but cant use Items
 */

#ifndef ANTIPATTERN_MONSTER_H
#define ANTIPATTERN_MONSTER_H

#include <string>
#include <vector>
#include <iostream>

#include "Entity.h"
#include "Monster.h"
#include "Skill.h"


class AntiPatternMonster : public  Entity, public Monster {
public:
	//give the Monster a name
	AntiPatternMonster(std::string name);
	~AntiPatternMonster();

	//return classname as str
	std::string getClassType(std::ostream& ostr) const {
		return "AntiPatternMonster"; 
	};

	//returns anything specific to a given class as a string used in operator<<
	std::string getNonBasicInfo(std::ostream& ostr) const { 
		return "good luck defeating me!";
	};

private:
	//Monster only has Skill vector
	std::vector<Skill> _skills;
};

#endif
