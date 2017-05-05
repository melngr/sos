/*  Day class to handle new Monster
 *  Each Day can generate a new Monster which scales with the number created
 *  Managed by the Dungeon class
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
	static const std::string DAYS_OF_WEEK[WEEK_LENGTH];

public: 
	Day() {
		_hoursOfDay = HOURS_IN_A_DAY; 
		_currDayInd = 0;
		_currentMonster = new Monster("eibooN");
		_currentMonster->setStats(1, 0, 20);
	};

	~Day() { delete _currentMonster; }
	//for convenience
	std::string getDayStr() { return DAYS_OF_WEEK[_currDayInd]; }
	void moveForwardOneDay() { 
		_currDayInd = (_currDayInd + 1) % WEEK_LENGTH;
		_hoursOfDay = HOURS_IN_A_DAY;
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Day& d);

	void setMonster(std::string mName, int att, int def, int hp){
		delete _currentMonster; //no leak on prev days monster. Make sure that this is stored already if sleep on it was called
		_currentMonster = new Monster(mName);
		_currentMonster->setStats(att, def, hp);
	}

	//day info
	int _hoursOfDay;
	unsigned int _currDayInd;   // 0 ... 6
	Monster* _currentMonster;
};

#endif

