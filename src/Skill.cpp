/*
 * Skill.cpp
 *
 * constructor and use of Skill
 * consumes uses
 */

#include <string>

#include "Skill.h"

Skill::Skill(std::string name, int maxuses) : Usable(name, maxuses) {
}

Skill::~Skill() {
}

int Skill::use(int inputval) {
	if (_uses <= 0) {
		return -1;
	}

	--_uses;
	return 0;
}

void Skill::discard() {
	delete(this);
}