#ifndef SKILLHACK_H
#define SKILLHACK_H

#include <string>
#include "Skill.h"

class SkillHack : Skill {
public:
	SkillHack(std::string name, int maxuses);
	~SkillHack();

	int use(int statvalue);
};

#endif