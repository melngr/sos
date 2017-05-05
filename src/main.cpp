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
#include "Combat.h"
#include "SkillFactory.h"
#include "Utilities.h"

// ----------------------------------------------------------------

void dungeonSetupTest(std::string playerName);
void printTimeInfo(Dungeon& d);
void run(Dungeon& d);
void study(Dungeon &d);
void displayStory(std::string& playerName);
void displayHelp();

int main(int argc, char** argv) {
	std::cout << "SOS! Surviving Open Source as a game experience" << std::endl;
	std::cout << "Currently an active project for CSCI2963" << std::endl;

	std::string playerName;
	std::cout << "Please enter a name: ";
	std::cin >> playerName;
	std::cout << std::endl;
	Dungeon dastardlyDungeon(playerName);

	displayStory(playerName);
	displayHelp();
	run(dastardlyDungeon);
	return 0;
}

// ----------------------------------------------------------------

//display the current day and time in Dungeon d
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

void displayStory(std::string& playerName) {
	std::cout << "Welcome to SOS, " << playerName << ", the world in which you are the" <<
			std::endl << "programmer and your groupmates are trying their best but are" <<
			std::endl << "making your life harder. You need to pull off a good grade and" <<
			std::endl << "and fix all of the code that they create. You'll be able to " <<
			std::endl << "check the clock, fix their monstrous mistakes, and study. Time " <<
			std::endl << "is yours to control, but use it carefully. Good Luck!" << std::endl;
}

//print all valid input commands to the console if requested
void displayHelp() {
	std::cout << "These are your options for input:" << std::endl <<
					"  \"Fight\" or \"f\" -> fight a monster" << std::endl <<
					"  \"Help\" or \"h\" -> print a the command list" << std::endl <<
					"  \"Quit\" or \"q\" -> quit the game before 30 days" << std::endl <<
					"  \"Study\" or \"s\" -> input a number greater than 0" << std::endl <<
					"  \"Time\" or \"t\" -> print the current time info" << std::endl <<
					"  \"Procrastinate\" or \"p\" -> input a number greater than 0" << std::endl <<
					"  \"Grade\" or \"g\" -> this is a measure of your success in this game" << std::endl;
	std::cout << "Note: If you don't fight a monster one day. It gets saved for you to fight" << std::endl
				<< "later, but beware its stats will have increased! Don't wait too long!" << std::endl;
}
//ask for #hours to study, then increment time and gameState accordingly
void study(Dungeon &d) {
	unsigned int hrs;
	std::cout << "For how many hours (between 0 and " << d.numHrs() << ")? ";
	std::cin >> hrs;
	while ( std::cin.fail() || hrs > d.numHrs() ) {
		std::cout << "Invalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> hrs;
	}
	// Post code
	d.subtractHrs(hrs);
}

void procrastinate(Dungeon &d) {
	unsigned int hrs;
	std::cout << "For how many hours (between 0 and " << d.numHrs() << ")? ";
	std::cin >> hrs;
	while ( std::cin.fail() || hrs > d.numHrs() ) {
		std::cout << "Invalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> hrs;
	}
	// Post code
	d.subtractHrs(hrs);
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
	float grade = 100;
	while ( d.getDaysPassed() < 30 ) {
		std::cout << "\nEnter what you want to do next: ";
		std::cin >> cmd;
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		
		//if the player opts to fight, display monster info and increment dungeon time
		if ( cmd == "f" || cmd == "fight" ) {
			std::cout << *(d.getPlayer()) <<  *(d.getMonster()) <<std::endl;
			Combat combatHandler(d.getPlayer(), d.getMonster());
			int victory = combatHandler.engageCombat(std::cout);

			if(victory != 2){ //
				d.subtractHrs(6);
			}
			if(victory == 0){ //lost fight, lose grade points
				grade -= 5;
			} else if(victory == 1) {
				if(grade < 100){
					grade += .5; //won fight, small bit of extra credit
				}
			}
		}

		//if the player asks for help, display the help commands
		else if ( cmd == "h" || cmd == "help" ) {
			displayHelp();
		}

		//if the player attempts to quit, break out of the main loop
		else if ( cmd == "q" || cmd == "quit") {
			break;
		}

		//if the player attempts to study, ask for #hours and modify time and gameState accordingly
		else if ( cmd == "s" || cmd == "study" ) {
			study(d);
		}

		//if the player asks for the time, return the current day and #hours
		else if ( cmd == "t" || cmd == "time") {
			// printTimeInfo(d);
			// I think this will be a little more useful to the user.
			std::cout << "Day " << d.getDaysPassed() << " out of 30, Hour " << (24 - d.numHrs()) << " of 24" << std::endl;
		}

		else if (cmd == "p" || cmd == "procrastinate"){
			procrastinate(d);
		}

		else if (cmd == "g" || cmd == "grade"){
			std::cout << grade << "\%" <<  std::endl;
		}

		//ignore any other input, as we have exhausted all valid commands
		else {
			std::cout << "Unknown command" << std::endl;
		}
	}

	std::cout << std::endl;
}

