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

#include "Dungeon.h"

Dungeon::Dungeon(std::string playerName){
	currDay = new Day(); 
	daysPassed = 0;
	std::ifstream ifstr("MonsterNameList.txt");

	if(!ifstr.good()){
		std::cerr << "Problem opening the monster name file" << std::endl;
	}

	std::string name;
	monsterTypes = new std::string[MONSTER_ARRAY_SIZE];

	unsigned int i = 0;
	while(getline(ifstr, name)){
		monsterTypes[i] = name;
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
		ostr << d.monsterTypes[i] << std::endl;
	}
	ostr << "Player: " << *(d.player_) << std::endl;

	ostr << "END OF DUNGEON OBJECT" << std::endl;
}

void Dungeon::progressToNextDay(){
	currDay->moveForwardOneDay();
}

void Dungeon::subtractHrs(float numHrs){
	float& currHrs = currDay->hoursOfDay_;
	if(numHrs >= currHrs){
		float remainder = numHrs - currHrs;
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
	monsterAtt = 5 + daysPassed*(0.3);
	monsterDef = 0 + daysPassed*1.1;
	int nameInd = 0;
	//int nameInd = rand() % std::min(daysPassed, MONSTER_ARRAY_SIZE);
	name = monsterTypes[nameInd];

}

void Dungeon::generateMonster(){
	int monsterHp, monsterAtt, monsterDef;
	std::string name;
	scaleStats(name, monsterAtt, monsterDef, monsterHp);
	currDay->setMonster(name, monsterAtt, monsterDef, monsterHp);
}