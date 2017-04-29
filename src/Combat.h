#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Skill.h"

class Combat {
public:
	Combat(Player *currentplayer, Monster *currentmonster);
	~Combat();

	void playerTurn(std::ostream& ostr);
	void monsterTurn(std::ostream& ostr);
	bool engageCombat(std::ostream& ostr);

private:
	Player* _player;
	Monster* _monster;
	bool _turn;
};

#endif