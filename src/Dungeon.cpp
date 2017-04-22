#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>

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
