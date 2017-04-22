/*
 * Monster.h
 *
 * represents opponents found in dungeons
 * have Skill like the Player but cant use Items
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

#include "Entity.h"
#include "Skill.h"
#include <vector>

class Monster : public  Entity {
public:
	//give the Monster a name
	Monster(std::string name);
	~Monster();

	//use Skill
	int useSkill(int index);
	int useItem(int index);
private:
	//Monster only has Skill vector
	std::vector<Skill> _skills;
};

#endif