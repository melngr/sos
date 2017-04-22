


#ifndef DUNGEON_H
#define DUNGEON_H


#include <string>
#include <vector>
#include "Monster.h"
#include <iostream>
#include "Day.h"



class Dungeon {
	static const int MONSTER_ARRAY_SIZE = 10;
public:
	Dungeon();
	~Dungeon() { delete currDay; };

	//Day object accessors
	std::string getDay() { return currDay->getDayStr(); }
	Monster* getMonster() { return currDay->currentMonster_; }
	float numHrs() {return currDay->hoursOfDay_;}

	void subtractHrs(float numHrs);
	friend std::ostream& operator<<(std::ostream& ostr, const Dungeon& d);


protected:
	Day* currDay;
	int daysPassed;
	std::string* monsterTypes;

	void progressToNextDay(); //moves to the next day, likely called from subtract hours
	Monster generateMonster(int maxIndex); //likely called from progressToNextDay


};
#endif
