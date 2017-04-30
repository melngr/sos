#ifndef SKILLDEBUG_H
#define SKILLDEBUG_H

#include <string>
#include "Skill.h"

class SkillDebug : Skill {
public:
	SkillDebug(std::string name, int maxuses);
	~SkillDebug();

	int use(int statvalue);
};

#endif