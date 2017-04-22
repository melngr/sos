


#ifndef DUNGEON_H
#define DUNGEON_H


#include <string>
#include <vector>
#include "Monster.h"
#include "Day.h"



class Dungeon {
public:
	Dungeon() { currDay = new Day(); daysPassed = 0;};
	~Dungeon() { delete currDay; };

	//Day object accessors
	std::string getDay() { return currDay->getDayStr(); }
	Monster* getMonster() { return currDay->currentMonster_; }
	float numHrs() {return currDay->hoursOfDay_;}

	void subtractHrs(float numHrs);


protected:
	Day* currDay;
	int daysPassed;


	void progressToNextDay(); //moves to the next day, likely called from subtract hours
	Monster generateMonster(int maxIndex); //likely called from progressToNextDay

};
#endif
