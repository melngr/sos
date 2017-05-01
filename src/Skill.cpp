/*
 * Skill.cpp
 *
 * constructor and use of Skill
 * consumes uses
 */

#include <string>

#include "Skill.h"

//Skill class; stores basic attributes about this skill (currently name and max #uses)
Skill::Skill(std::string name, int maxuses) : Usable(name, maxuses) {
}

//delete any data that the Skill class put on the heap (currently nothing to delete)
Skill::~Skill() {
}

void Skill::refreshSkills() {
	_uses = _maxuses;
}

//use this skill as specified by inputVal
int Skill::use(int statvalue) {
	if (_uses <= 0) {
		return -1;
	}

	--_uses;
	return 0;
}

//destroy this skill
void Skill::discard() {
	delete(this);
}
