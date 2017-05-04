/**
Combat.h

header for Combat handler in game
manages Player and Monster objects with turn based combat
*/

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
	void displayOptions(std::ostream& ostr);
	void monsterTurn(std::ostream& ostr);
	int engageCombat(std::ostream& ostr);

	void setMonster(Monster* newMonster);

private:
	//Player and Monster are dynamically allocated in the Dungeon
	Player* _player;
	Monster* _monster;
	//Tracks turn
	bool _turn;
};

#endif
