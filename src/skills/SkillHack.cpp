#include <string>
#include "Skill.h"
#include "SkillHack.h"

SkillHack::SkillHack(std::string name, int maxuses) : Skill(name, maxuses) {
	_name = "Hack Solution";
	_uses = 30;
	_maxuses = 30;
}

SkillHack::~SkillHack() {
}

int SkillHack::use(int statvalue) {
	if (_uses > 0) {
		--_uses;
		return 20;
	}
	else {
		return 0;
	}
}