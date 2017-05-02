/** main.cpp
 *  This file contains the main method for the game. It handles menu 
 *  options, generates game world, and manages game interactions.
 */

#include <iostream>
#include <algorithm>
#include "Entity.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"
#include "Usable.h"
#include "Dungeon.h"

// ----------------------------------------------------------------

void dungeonSetupTest(std::string playerName);
void printTimeInfo(Dungeon& d);
void run(Dungeon& d); 
void printHelp();


int main(int argc, char** argv) {

	std::cout << "SOS! Surviving Open Source as a game experience" << std::endl;
	std::cout << "Currently an active project for CSCI2963" << std::endl;

	std::string playerName;
	std::cout << "Please enter a name: ";
	std::cin >> playerName;
	Dungeon dastardlyDungeon(playerName);

	std::cout << 
		std::endl << "Welcome to SOS, " << playerName << ", the world in which you are the" << 
		std::endl << "programmer and your groupmates are trying their best but are" <<
		std::endl << "making your life harder. You need to pull off a good grade and" <<
		std::endl << "and fix all of the code that they create. You'll be able to " <<
		std::endl << "check the clock, fix their monstrous mistakes, and study. Time " <<
		std::endl << "is yours to control, but use it carefully. Good Luck!" << std::endl;
	
	printHelp();
	
	run(dastardlyDungeon);
	return 0;
}

// ----------------------------------------------------------------

void printTimeInfo(Dungeon& d){
	std::cout << d.getDay() << " " << d.getDaysPassed() << " " << d.numHrs() << std::endl;
}

// ----------------------------------------------------------------

//testing setup
void dungeonSetupTest(std::string playerName){
	Dungeon d(playerName);
	d.addPlayerSkill("HI", 4);
	d.addPlayerSkill("Yo", 4);
	d.addPlayerSkill("MEW 2", 4);
	d.addPlayerSkill("MEW 5", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("HI", 4);
	d.addPlayerSkill("Yo", 4);
	d.addPlayerSkill("MEW 2", 4);
	d.addPlayerSkill("MEW 5", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("next UP!", 4);
	d.addPlayerSkill("next UP!", 4);
	std::cout << d.numHrs() << std::endl;
	std::cout << d.getDay() << std::endl;
	d.subtractHrs(49);
	std::cout << d.numHrs() << std::endl;
	std::cout << d.getDay() << std::endl;
	d.subtractHrs(10);
	std::cout << d.numHrs() << std::endl;
	d.subtractHrs(10);
	std::cout << d.numHrs() << std::endl;
	std::cout << d << std::endl;
}

// ----------------------------------------------------------------

/** Run the dungeon.
 *  @param d, the current Dungeon object
 *  @modifies d by performing the dungeon actions
 *  @effects Allows the user to loop through the dungeon object 
 *           performing one action at a time until 30 days pass.
 */
void run(Dungeon& d) {
	std::string cmd;
	
	while ( d.getDaysPassed() < 30 ) {
		std::cout << "\nEnter what you want to do next: ";
		std::cin >> cmd;
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		
		if ( (cmd == "f") || (cmd == "fight") ) {
			//TODO: implement actual mechanics
			std::cout << *(d.getMonster()) << std::endl;
			d.subtractHrs(24);
		} else if ( (cmd == "h") || (cmd == "help") ) {
			printHelp();
		} else if ( (cmd == "q") || (cmd == "quit") ) {
			break;
		} else if ( (cmd == "s") || (cmd == "study") ) {
			unsigned int hrs;
			std::cout << "For how many hours (between 0 and " << d.numHrs() << ")? ";
			std::cin >> hrs;
			while ( std::cin.fail() || hrs > d.numHrs() ) {
				std::cout << "Invalid input!" << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cin >> hrs;
			}
			// TODO: need to figure out how we modify player stats for studying
			d.subtractHrs(hrs);
			continue;
		} else if ( (cmd == "t") || (cmd == "time") ) {
			// printTimeInfo(d);
			// I think this will be a little more useful to the user.
			std::cout << "Day " << d.getDaysPassed() << " out of 30; Hour " << (24 - d.numHrs()) << std::endl;
		} else {
			std::cout << "Unknown command" << std::endl;
		}
	}

	std::cout << std::endl;
}

void printHelp(){
	std::cout << "These are your options for input:" << std::endl << 
				"  \"Fight\" or \"f\" -> fight a monster" << std::endl << 
				"  \"Quit\" or \"q\" -> quit the game before 30 days" << std::endl << 
				"  \"Study\" or \"s\" -> input a number greater than 0" << std::endl << 
				"  \"Time\" or \"t\" -> print the current time info" << std::endl;
	std::cout << "Note: if you don't fight a monster and the day ends, then the monster" << std::endl
			  << "is stored and you can fight it later. Beware, they get a bit stronger as time passes!" << std::endl;
}