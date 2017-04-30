#ifndef SKILLPLAN_H
#define SKILLPLAN_H

#include <string>
#include "Skill.h"

class SkillPlan : Skill {
public:
	SkillPlan(std::string name, int maxuses);
	~SkillPlan();

	int use(int statvalue);
};

#endif