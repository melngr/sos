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

	virtual int use(int statvalue);
	void discard();
	std::string getClassType() {return "Skill"; };
	
private:

};

#endif