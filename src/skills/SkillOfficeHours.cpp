#include <string>
#include "Skill.h"
#include "SkillOfficeHours.h"

SkillOffice::SkillOffice(std::string name, int maxuses) : Skill(name, maxuses) {
	_name = "Attend Office Hours";
	_uses = 5;
	_maxuses = 5;
}

SkillOffice::~SkillOffice() {
}

int SkillOffice::use(int statvalue) {
	if (_uses > 0) {
		--_uses;
		int damage = 40;
		damage += (0.25 * statvalue);
		return damage;
	}
	else {
		return 0;
	}
}