/*
 * main.cpp
 *
 * "engine" of the game for now, subject to change
 * handles menu+options at start
 * generates game world for player
 * manages game interactions
*/

#include <iostream>
#include <algorithm>
#include "Entity.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"
#include "Usable.h"
#include "Dungeon.h"


void dungeonSetupTest(std::string playerName);
void printTimeInfo(Dungeon& d);
void start(Dungeon& d);



int main(int argc, char** argv) {

	std::cout << "SOS! Surviving Open Source as a game experience" << std::endl;
	std::cout << "Currently an active project for CSCI2963" << std::endl;

	std::string playerName;
	std::cout << "Please enter a name:" << std::endl;
	std::cin >> playerName;
	Dungeon dastardlyDungeon(playerName);
	std::cout << std::endl << std::endl;
	std::cout << "Welcome to SOS, " << playerName << " the world in which you are the programmer and your groupmates are" << std::endl;
	std::cout << "trying their best, but are only making your life harder." << std::endl;
	std::cout << "You need to pull off a good grade and fix all the code that they create. Whatever" << std::endl;
	std::cout << "free time you have is up to you to use to the utmost. Don't forget studying and free time" << std::endl;
	std::cout << "are important!" << std::endl;
	//dungeonSetupTest(playerName);
	start(dastardlyDungeon);
	return 0;
}

void printTimeInfo(Dungeon& d){
	std::cout << d.getDay() << " " << d.getDaysPassed() << " " << d.numHrs() << std::endl;
}

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

void start(Dungeon& d){
	std::string cmd;
	while(d.getDaysPassed() < 30){
		std::cout << "enter what you want to do next: " << std::endl;
		std::cin >> cmd;
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		if(cmd == "t" || cmd == "T"){
			printTimeInfo(d);
		}
		if(cmd == "study" || cmd == "s"){
			int hrs;
			std::cout << "For How many hours (int)? " << std::endl;
			std::cin >> hrs;
			while(std::cin.fail() || hrs > d.numHrs()){
				std::cout << "invalid input!" << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cin >> hrs;
			}
			//Post code
			d.subtractHrs(hrs);
			continue;
		} else if (cmd == "f" || cmd == "fight"){
			std::cout << *(d.getMonster()) << std::endl;
			d.subtractHrs(24);
		}else if(cmd != "t"){
			std::cout << "Unknown command try again" << std::endl;
			continue;
		}
	}
	
}

