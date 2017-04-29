#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Skill.h"
#include "Combat.h"

Combat::Combat(Player *currentplayer, Monster *currentmonster) {
	_player = currentplayer;
	_monster = currentmonster;
	_turn = true;
}

Combat::~Combat() {
}

void Combat::playerTurn(std::ostream& ostr) {
	std::string action = "";
	ostr << "Player Turn!" << std::endl;
	ostr << "What will you do?" << std::endl
	     << "Show info [i]" << std::endl
	     << "Use skill [s]" << std::endl
	     << "Procrastinate [f]" << std::endl
	     << "Pass turn [p]" << std::endl;
	std::cin >> action;
	while (true) {
		if (action == "i") {
			_player->getNonBasicInfo(ostr);
		}
		else if (action == "s") {
			int skillchoice;
			ostr << "What skill?" << std::endl;
			std::cin >> skillchoice;
			int damage = _player->useSkill(skillchoice);

			_monster->updateStamina(-damage);
			if (_monster->getStamina() <= 0) {
				break;
			}
		}
		else if (action == "f") {
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

void Combat::monsterTurn(std::ostream& ostr) {
	ostr << "Monster Turn!" << std::endl;
	//random generate number to call monster skill
	//inflict damage to player
}

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