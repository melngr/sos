#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <string>
#include <vector>

#include "Day.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"

class Dungeon {
	static const int MONSTER_ARRAY_SIZE = 15;

public:
	Dungeon(std::string);
	~Dungeon() { 
		delete _currDay; 
		delete [] _monsterTypes; 
		delete [] _monsterNames; 
		delete _player; 
	};

	// Day object accessors
	std::string getDay() { return _currDay->getDayStr(); }
	Monster* getMonster() { return _currDay->_currentMonster; }
	Player* getPlayer() { return _player; }
	int getDaysPassed() { return _daysPassed; }
	int numHrs() { return _currDay->_hoursOfDay; }

	void subtractHrs(int numHrs);
	void addPlayerSkill(std::string newSkill, int maxuses){
		_player->learnSkill(newSkill, maxuses);
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Dungeon& d);

protected:
	Day* _currDay;
	int _daysPassed;
	std::string* _monsterNames;
	std::string* _monsterTypes;   // correlates directly with names Mtype[0] goes with MName[0]
	std::vector<Monster*> _pastMonsters;
	Player* _player;

	void readFile(char* inFileName, std::ifstream &ifstr); //attempt to load the specified file
	void loadMonsterData();   // loads in monster attributes from MonsterNameList.txt
	void progressToNextDay();   // moves to the next day, likely called from subtract hours
	void generateMonster();   // likely called from progressToNextDay
	void scaleStats(std::string& name, int& monsterAtt, int& monsterDef, int& monsterHp);

};
#endif

