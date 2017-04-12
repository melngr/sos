/*
 * Player.cpp
 *
 * contains implementations for Player specific functions
 * Player objects can use Item or use Skill objects
 */

#include <string>

#include "Player.h"

Player::Player(std::string name) : Entity() {
	_name = name;
}

int Player::useSkill(int index) {
	return 0;
}

int Player::useItem(int index) {
	return 0;
}