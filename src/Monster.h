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
	/*
		param name: the name of the monster
		requires: true
		modifies: this
		effects: makes a new monster with the name. 

		I think this isn't going to work if we have sub
		classes with a type because we would need to pass that as well
	*/
	Monster(std::string name);
	~Monster();

	std::string getClassType(std::ostream& ostr) const {
		return "monster"; 
	}; //return classname as str
	std::string getNonBasicInfo(std::ostream& ostr) const { 
		return "good luck defeating me!";
	}; //returns anything specific to a given class as a string used in operator<<


	/*
		param: index, the index of the skill in the vector. 
		@modifies: depends on the type of skill, none or this
		requires: 

		May want to change
		this into a map or set. That way we just need the name and it's super close
		to cnst time b/c of the prob relatively small size of skills
	*/
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
	//std::vector<Skill> _weaknesses;
};

#endif