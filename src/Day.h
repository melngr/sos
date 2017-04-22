#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include "Monster.h"


class Day {
	#define  HOURS_IN_A_DAY 24;
public: 
	Day() {
		hoursOfDay_ = HOURS_IN_A_DAY; 
		currDayInd_ = 0;
		currentMonster_ = new Monster("");
	};

	//for convenience
	std::string getDayStr() { return daysOfWeek_[currDayInd_]; }
	void moveForwardOneDay() { 
		currDayInd_ = (currDayInd_ + 1) % 7;
		hoursOfDay_ = HOURS_IN_A_DAY;
	 }


	//day info
	float hoursOfDay_;
	unsigned int currDayInd_; //0...6
	static const std::string daysOfWeek_[7]; //defined in cpp
	Monster* currentMonster_;
};

#endif