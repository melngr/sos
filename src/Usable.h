/*
 * Usable.h
 *
 * class file as parent of Skill and Item
 * Skill are Usable with infinite(recharge) uses and effects based on Player/Monster
 * Item are Usable with finite uses and have fixed effects on the user
 */

#ifndef USABLE_H
#define USABLE_H

#include <string>

class Usable {
public:
	//Constructor
	Usable(std::string name, int maxuses);
	virtual ~Usable();

	//accessors
	std::string getName();
	int getUses();
	int getMaxuses();

	void updateName(std::string name);

	//use and discard vary by Skill or Item
	virtual int use(int inputval) = 0;
	virtual void discard() = 0;

protected:
	std::string _name;
	int _uses;
	int _maxuses;
};

#endif