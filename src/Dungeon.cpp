#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

#include "Dungeon.h"

Dungeon::Dungeon(std::string playerName){
	currDay = new Day(); 
	daysPassed = 0;
	std::ifstream ifstr("MonsterNameList.txt",std::ifstream::in);

	if(!ifstr.good()){
		//if we can't find the monster list, fall back to the parent directory
		ifstr.open("../MonsterNameList.txt",std::ifstream::in);
		if (!ifstr.good()) {
			//couldn't find the monster list in the working or parent dir
			std::cerr << "Problem opening the monster name file" << std::endl;
		}
	}

	std::string line, name, type;
	std::string delim = ", ";
	
	monsterNames = new std::string[MONSTER_ARRAY_SIZE];
	monsterTypes = new std::string[MONSTER_ARRAY_SIZE];

	unsigned int i = 0;
	
	//load in monster names and corresponding types line by line from MonsterNameList.txt
	while(getline(ifstr, line)){
		name = line.substr(0, line.find(delim));
		type = line.substr(line.find(delim) + 2, line.size());
		monsterNames[i] = name;
		monsterTypes[i] = type;
		i+=1;
	}

	assert(i == MONSTER_ARRAY_SIZE);

	player_ = new Player(playerName);
	//srand(time(NULL)); // generate a random seed
}

std::ostream& operator<<(std::ostream& ostr, const Dungeon& d){
	ostr << std::endl << "PRINTING DUNGEON" << std::endl << std::endl;
	ostr << "Day: " << *(d.currDay) << std::endl;
	ostr << "daysPassed: " << d.daysPassed << std::endl;
	ostr << "Monsters Stored: " << std::endl; 
	for(int i = 0; i < d.MONSTER_ARRAY_SIZE; i++){
		ostr << d.monsterNames[i] << " " << d.monsterTypes[i] << std::endl;
	}
	ostr << "Player: " << *(d.player_) << std::endl;

	ostr << "END OF DUNGEON OBJECT" << std::endl;
	
	return ostr;
}

void Dungeon::progressToNextDay(){
	currDay->moveForwardOneDay();
}

void Dungeon::subtractHrs(float numHrs){
	float& currHrs = currDay->hoursOfDay_;
	if(numHrs >= currHrs){
		float remainder = numHrs - currHrs;
		//TODO: if we want to allow skipping days through activities we need to make sure a monster is generated
		//and then then stored(we only should need to auto store if remainder >= 24)
		progressToNextDay(); //make day move to the next day
		subtractHrs(remainder);
	}else{
		currHrs -= numHrs;
	}
}

void Dungeon::scaleStats(std::string name, int& monsterAtt, int& monsterDef, int& monsterHp){
	//based on days passed higher as more days pass.
	int base = 100;
	monsterHp = base + daysPassed*2;
	monsterAtt = 5 + ceil(daysPassed*(0.33));
	monsterDef = 0 + ceil(daysPassed*1.2);
	int nameInd = 0;
	//int nameInd = rand() % std::min(daysPassed, MONSTER_ARRAY_SIZE);
	name = monsterNames[nameInd];

}

void Dungeon::generateMonster(){
	int monsterHp, monsterAtt, monsterDef;
	std::string name;
	scaleStats(name, monsterAtt, monsterDef, monsterHp);
	currDay->setMonster(name, monsterAtt, monsterDef, monsterHp);
}