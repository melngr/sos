


#ifndef DUNGEON_H
#define DUNGEON_H


#include <string>
#include <vector>
#include "Monster.h"
#include <iostream>
#include "Day.h"
#include "Player.h"
#include "Skill.h"



class Dungeon {
	static const int MONSTER_ARRAY_SIZE = 15;
public:
	Dungeon(std::string);
	~Dungeon() { 
		delete currDay; 
		delete [] monsterTypes; 
		delete player_; 
	};

	//Day object accessors
	std::string getDay() { return currDay->getDayStr(); }
	Monster* getMonster() { return currDay->currentMonster_; }
	float numHrs() {return currDay->hoursOfDay_;}

	void subtractHrs(float numHrs);
	friend std::ostream& operator<<(std::ostream& ostr, const Dungeon& d);

	void addPlayerSkill(std::string newSkill, int maxuses){
		player_->learnSkill(newSkill, maxuses);
	}

protected:

	Day* currDay;
	int daysPassed;
	std::string* monsterTypes;
	std::vector<Monster*> pastMonsters;
	Player* player_;

	void progressToNextDay(); //moves to the next day, likely called from subtract hours
	void generateMonster(); //likely called from progressToNextDay
	void scaleStats(std::string name, int& monsterAtt, int& monsterDef, int& monsterHp);

};
#endif
