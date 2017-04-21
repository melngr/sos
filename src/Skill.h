/*
 * Skill.h
 *
 * Skill class from Usable
 * Skill are available to Player and Monster
 * Player Skill either do damage or change stats
 */

#ifndef SKILL_H
#define SKILL_H

#include <string>

#include "Usable.h"

class Skill : public Usable {
public:
	Skill(std::string name, int maxuses);
	~Skill();

	int use(int inputval);
	void discard();

private:
};

#endif