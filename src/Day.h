/**
Day class to handle new Monster
Each Day can generate a new Monster which scales with the number created
Managed by the Dungeon class
*/

#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"


class Day {
	static const int HOURS_IN_A_DAY = 24;
	static const int WEEK_LENGTH = 7;
public: 
	Day() {
		hoursOfDay_ = HOURS_IN_A_DAY; 
		currDayInd_ = 0;
		currentMonster_ = new Monster("eibooN");
		currentMonster_->setStats(1, 0, 20);
	};

	~Day() { delete currentMonster_; }
	//for convenience
	std::string getDayStr() { return daysOfWeek_[currDayInd_]; }
	void moveForwardOneDay() { 
		currDayInd_ = (currDayInd_ + 1) % WEEK_LENGTH;
		hoursOfDay_ = HOURS_IN_A_DAY;
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Day& d); //doesn't actually need to be friend could've defined outside class

	void setMonster(std::string mName, int att, int def, int hp){
		delete currentMonster_; //no leak on prev days monster. Make sure that this is stored already if sleep on it was called
		currentMonster_ = new Monster(mName);
		currentMonster_->setStats(att, def, hp);
	}

	
	//day info
	float hoursOfDay_;
	unsigned int currDayInd_; //0...6
	static const std::string daysOfWeek_[WEEK_LENGTH]; //defined in cpp, cant make this use WEEK_LENGTH?
	Monster* currentMonster_;
};

#endif
