/*
 * Monster.h
 *
 * represents opponents found in dungeons
 * have Skill like the Player but cant use Items
 */

#include <string>

#include "Entity.h"

class Monster : public  Entity {
public:
	//give the Monster a name
	Monster(std::string name);

	//use Skill
	int useSkill(int index);

private:
	//Monster only has Skill vector
	//std::vector<Skill> _skills
};