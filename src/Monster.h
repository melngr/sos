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

	//use Skill
	int useSkill(int index);
	int useItem(int index);

	friend std::ostream& operator<<(std::ostream& ostr, const Monster& m); 
private:
	//Monster only has Skill vector
	std::vector<Skill> _skills;
};

#endif