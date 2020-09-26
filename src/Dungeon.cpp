#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
// #include <iostream>
#include <sstream>
// #include <string>
// #include <vector>

#include "Dungeon.h"

/*  Default constructor.
 *  @param playerName, string with user-inputted name for player
 *  @effects Creates a new Dungeon object.
 */
Dungeon::Dungeon(std::string playerName) {
	_currDay = new Day(); 
	_daysPassed = 0;
	_player = new Player( playerName );
	loadMonsterData();
	// srand(time(NULL));   // generate a random seed
}

/*  File loader.
 *  @param inFileName, char* with file containing Monster names
 *  @param ifstr, instream for reading file
 *  @modifies ifstr, modified to read individual files
 *  @effects Loads all monster information from 'inFileName'.
 */
void Dungeon::readFile(char* inFileName, std::ifstream &ifstr) {
	// search up through directory to find file (max of 20 levels up)
	unsigned int parentDirNum = 0;
	std::string dirStr = inFileName;
	ifstr.open(dirStr.c_str(),std::ifstream::in);

	while ( (!ifstr.good()) && (parentDirNum < 20) ) {
		dirStr = "../" + dirStr;
		++parentDirNum;
		ifstr.open(dirStr.c_str(),std::ifstream::in);
	}

	// verify that we found the file
	if ( !ifstr.good() ) {
		// error finding file within max directory search
		std::cerr << "Problem opening monster name file: " << inFileName << std::endl;
	}
}

/*  Load Monster attributes.
 *  @modifies _monsterNames, _monsterTypes
 *  @effects Pulls in data from MonsterNamesList and loads into 
 *           '_monsterNames' and '_monterTypes'
 */
void Dungeon::loadMonsterData() {
	// attempt to load in MonsterNameList.txt
	std::ifstream ifstr;
	// char* file = (char*) ("MonterNameList.txt");
	readFile("MonsterNameList.txt", ifstr);

	std::string line, name, type, delim = ", ";

	_monsterNames = new std::string[MONSTER_ARRAY_SIZE];
	_monsterTypes = new std::string[MONSTER_ARRAY_SIZE];

	unsigned int i = 0;

	// load in names to '_monsterNames' and types to '_monsterTypes'
	while ( getline(ifstr, line) ) {
		name = line.substr(0, line.find(delim));
		type = line.substr(line.find(delim) + 2, line.size());
		_monsterNames[i] = name;
		_monsterTypes[i] = type;
		++i;
	}

	// assert that monster data arrays have length 'MONSTER_ARRAY_SIZE'
	assert( i == MONSTER_ARRAY_SIZE );
}

/*  Standard toString operation.
 *  @param ostr, current outstream for program
 *  @param d, Dungeon object to print
 *  @modifies ostr
 *  @effects Loads 'ostr' with all data available in 'd'.
 *  @return ostr
 */
std::ostream& operator<<(std::ostream& ostr, const Dungeon& d) {
	ostr << std::endl << "PRINTING DUNGEON" << std::endl << std::endl;
	ostr << "Day: " << *(d._currDay) << std::endl;
	ostr << "daysPassed: " << d._daysPassed << std::endl;
	ostr << "Monsters Stored: " << std::endl; 
	for ( unsigned int i = 0; i < d.MONSTER_ARRAY_SIZE; ++i ) {
		ostr << d._monsterNames[i] << " " << d._monsterTypes[i] << std::endl;
	}
	ostr << "Player: " << *(d._player) << std::endl;
	ostr << "END OF DUNGEON OBJECT" << std::endl;
	
	return ostr;
}

/*  Time progression.
 *  @modifies _daysPassed, _currDay
 *  @effects Increments '_daysPassed' and iterates in '_currDay'
 */
void Dungeon::progressToNextDay(){
	++_daysPassed;
	generateMonster();
	_currDay->moveForwardOneDay();
}

/*  Hour decrementing operation.
 *  @param numHrs
 *  @modifies _currDay->_hoursOfDay
 *  @effects Decreases '_currDay->_hoursOfDay' by 'numHrs'
 */
void Dungeon::subtractHrs(int numHrs){
	int& currHrs = _currDay->_hoursOfDay;
	if ( numHrs >= currHrs ) {
		int remainder = (numHrs - currHrs);
		//TODO: if we want to allow skipping days through activities we need to make sure a monster is generated
		//and then then stored(we only should need to auto store if remainder >= 24)
		progressToNextDay();   //make day move to the next day
		subtractHrs(remainder);
	} else {
		currHrs -= numHrs;
	}
}

/*  Monster stats modifier.
 *  @param name, name from Monster object
 *  @param monsterAtt, attack from Monster object
 *  @param monsterDef, defense from Monster object
 *  @param monsterHp, health from Monster object
 *  @modifies name, monsterAtt, monsterDef, monsterHp
 *  @effects Scales passed Monter stats to '_daysPassed'
 */
void Dungeon::scaleStats(std::string& name, int& monsterAtt, int& monsterDef, int& monsterHp){
	//based on days passed higher as more days pass.
	int base = 100;
	monsterHp = (base + _daysPassed * 2);
	monsterAtt = (5 + ceil( _daysPassed * 0.33 ));
	monsterDef = (0 + ceil( _daysPassed * 1.2 ));
	int minSize = ( _daysPassed < MONSTER_ARRAY_SIZE ? _daysPassed : MONSTER_ARRAY_SIZE );
	int nameInd = (rand() %  minSize);//std::max(daysPassed)//, Dungeon::MONSTER_ARRAY_SIZE);
	name = _monsterNames[nameInd];
}

/*  Creates new Monster object.
 *  @modifies _currDay
 *  @effects Assigns a new Monster to '_currDay'.
 */
void Dungeon::generateMonster(){
	int monsterHp, monsterAtt, monsterDef;
	std::string name;
	scaleStats(name, monsterAtt, monsterDef, monsterHp);
	_currDay->setMonster(name, monsterAtt, monsterDef, monsterHp);
	_currDay->_currentMonster->getName();
}
