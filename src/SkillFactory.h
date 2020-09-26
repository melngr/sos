#ifndef SKILL_FACTROY_
#define SKILL_FACTROY_


#include <string>

#include "Skill.h"
#include "SkillHack.h"

class SkillFactory {
public:
	/*
		param: skillName, the name of the skill we want to create a new instance of
		param: maxUses, the maxUses in a SINGLE fight
		requires: true
		returns: a pointer to an object of the desired type with maxUses per fight
	*/
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