#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Skill.h"
#include "Combat.h"
#include "Utilities.h"

//generate a Combat handler with the given Player and Monster
Combat::Combat(Player *currentplayer, Monster *currentmonster) {
	_player = currentplayer;
	_monster = currentmonster;
	_turn = true;
}

//display the base options for the player's turn
void Combat::displayOptions(std::ostream& ostr) {
	ostr << "Player Turn!" << std::endl;
	ostr << "What will you do?" << std::endl
		<< "Show info [u]" << std::endl
		<< "Use skill [i]" << std::endl
		<< "Procrastinate [o]" << std::endl
		<< "Pass turn [p]" << std::endl;
}

Combat::~Combat() {
}

/**
Player turn options are received with cin
Users can choose several options from attacking to passing the turn
*/
void Combat::playerTurn(std::ostream& ostr) {
	std::string action = "";
	displayOptions(ostr);
	while (true) {
		std::cin >> action;
		if (equalsIgnoreCase(action,"u")) {
			ostr << _player->getNonBasicInfo(ostr);
		}
		else if (equalsIgnoreCase(action, "i")) {
			std::string skillChoice;
			int skillIndex = -1;
			//loop until the player enters a valid skill name that they possess
			while (true) {
				ostr << "What skill (type the name of one of your skills, or q to cancel)?" << std::endl;
				std::getline(std::cin, skillChoice);
				if (equalsIgnoreCase(skillChoice, "q") || equalsIgnoreCase(skillChoice,"quit")) {
					break;
				}
				skillIndex = _player->skillIndex(skillChoice);
				if (skillIndex != -1) {
					break;
				}
			}
			//if we opted to exit the skill selection menu (indicated by invalid skill selection) return to option select
			if (skillIndex == -1) {
				displayOptions(ostr);
				continue;
			}
	
			int damage = _player->useSkill(skillIndex);
			std::cout << "DMG: " << damage << std::endl;
			_monster->updateStamina(-damage);
			if (_monster->getStamina() <= 0) {
				break;
			}
		}
		else if (equalsIgnoreCase(action,"o")) {
			ostr << "Took a break :)" << std::endl;
		}
		else if (equalsIgnoreCase(action, "p")) {
			ostr << "Giving up???" << std::endl;
			break;
		}
		else {
			ostr << "What?" << std::endl;
			continue;
		}
	}
	return;
}

/**
Monster turns are managed by the game as weighted random selection of skills
Monster objects cannot use Item
*/
void Combat::monsterTurn(std::ostream& ostr) {
	ostr << "Monster Turn!" << std::endl;
}

/**
Engage combat function called by Dungeon when the Player chooses to fight
Alternates turns for Player and Monster calling the respective turn function

Returns 1 when the Player wins and 0 for a loss, and 2 if the fight never occurred (no time passes)
*/
int Combat::engageCombat(std::ostream& ostr) {
	if(_monster->getStamina() == 0){
		ostr << "Silly, You already beat this monster into the dust! You can't kill him twice. " << std::endl
		 << "Try again tomorrow!" << std::endl;
		return 2;
	}
	while ((_player->getStamina() > 0) && (_monster->getStamina() > 0)) {
		if (_turn) {
			ostr << "hi!" << std::endl;
			playerTurn(ostr);
			if (_monster->getStamina() <= 0) {
				ostr << "You won the fight!" << std::endl;
				_player->resetStamina();
				return 1;
			}
			_turn = false;
		}
		else {
			monsterTurn(ostr);
			_turn = true;
		}
	}
	_monster->resetStamina();
	_player->resetStamina();
	ostr << "You lost the fight :(, you will suffer a grade penalty for this!" << std::endl;
	return 0;
}

void Combat::setMonster(Monster* newMonster){
	_monster = newMonster;
}
