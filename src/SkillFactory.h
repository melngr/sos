#ifndef SKILL_FACTROY_
#define SKILL_FACTROY_


#include <string>

#include "Skill.h"
#include "skills/SkillHack.h"

class SkillFactory {
public:
	static Skill* getSkill(std::string skillName, int maxUses){
		if(skillName == "Hack Solution"){
			Skill* newSkill = new SkillHack("Hack Solution", maxUses);
			return newSkill;
		}else{
			return NULL;
		}
	};
};

#endif