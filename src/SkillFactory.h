#ifndef SKILL_FACTROY_
#define SKILL_FACTROY_


#include <string>

#include "Skill.h"
#include "skills/SkillHack.h"

class SkillFactory {
public:
	static Skill* getSkill(std::string skillName){
		if(skillName == "Hack Solution"){
			Skill* newSkill = new SkillHack("Hack Solution", 30);
			return newSkill;
		}else{
			return NULL;
		}
	};
};

#endif