#include <string>
#include "Skill.h"
#include "SkillDebugger.h"

SkillDebug::SkillDebug(std::string name, int maxuses) : Skill(name, maxuses) {
	_name = "Use Debugger";
	_uses = 15;
	_maxuses = 15;
}

SkillDebug::~SkillDebug() {
}

int SkillDebug::use(int statvalue) {
	if (_uses > 0) {
		--_uses;
		int damage = 15;
		damage += (1.0 * statvalue);
		return damage;
	}
	else {
		return 0;
	}
}