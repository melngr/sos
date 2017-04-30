#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Skill.h"
#include "Combat.h"

//generate a Combat handler with the given Player and Monster
Combat::Combat(Player *currentplayer, Monster *currentmonster) {
	_player = currentplayer;
	_monster = currentmonster;
	_turn = true;
}

Combat::~Combat() {
}

/**
Player turn options are received with cin
Users can choose several options from attacking to passing the turn
*/
void Combat::playerTurn(std::ostream& ostr) {
	std::string action = "";
	ostr << "Player Turn!" << std::endl;
	ostr << "What will you do?" << std::endl
	     << "Show info [u]" << std::endl
	     << "Use skill [i]" << std::endl
	     << "Procrastinate [o]" << std::endl
	     << "Pass turn [p]" << std::endl;
	std::cin >> action;
	while (true) {
		if (action == "u") {
			_player->getNonBasicInfo(ostr);
		}
		else if (action == "i") {
			int skillchoice;
			ostr << "What skill?" << std::endl;
			std::cin >> skillchoice;
			int damage = _player->useSkill(skillchoice);

			_monster->updateStamina(-damage);
			if (_monster->getStamina() <= 0) {
				break;
			}
		}
		else if (action == "o") {
			ostr << "Took a break :)" << std::endl;
		}
		else if (action == "p"){
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

Returns true when the Player wins and false if the Monster wins
*/
bool Combat::engageCombat(std::ostream& ostr) {
	while ((_player->getStamina() > 0) && (_monster->getStamina() > 0)) {
		if (_turn) {
			playerTurn(ostr);
			if (_monster->getStamina() <= 0) {
				return true;
			}
			_turn = false;
		}
		else {
			monsterTurn(ostr);
			_turn = true;
		}
	}
	return false;
}
