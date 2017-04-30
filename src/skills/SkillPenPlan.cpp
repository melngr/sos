#include <string>
#include "Skill.h"
#include "SkillPenPlan.h"

SkillPlan::SkillPlan(std::string name, int maxuses) : Skill(name, maxuses) {
	_name = "Plan Ahead";
	_uses = 20;
	_maxuses = 20;
}

SkillPlan::~SkillPlan() {
}

int SkillPlan::use(int statvalue) {
	if (_uses > 0) {
		--_uses;
		int damage = 25;
		damage += (0.5 * statvalue);
		return damage;
	}
	else {
		return 0;
	}
}