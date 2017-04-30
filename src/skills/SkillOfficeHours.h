#ifndef SKILLOFFICE_H
#define SKILLOFFICE_H

#include <string>
#include "Skill.h"

class SkillOffice : Skill {
public:
	SkillOffice(std::string name, int maxuses);
	~SkillOffice();

	int use(int statvalue);
};

#endif