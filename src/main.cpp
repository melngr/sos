/*
 * main.cpp
 *
 * "engine" of the game for now, subject to change
 * handles menu+options at start
 * generates game world for player
 * manages game interactions
*/

#include <iostream>
#include "Entity.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"
#include "Usable.h"
#include "Dungeon.h"

int main(int argc, char** argv) {
	std::cout << "SOS! Surviving Open Source as a game experience" << std::endl;
	std::cout << "Currently an active project for CSCI2963" << std::endl;

	Dungeon d;
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
	
	return 0;
}
