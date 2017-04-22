/*
 * Player.cpp
 *
 * contains implementations for Player specific functions
 * Player objects can use Item or use Skill objects
 */

#include <string>
#include <sstream>
#include "Player.h"

Player::Player(std::string name) : Entity(name) {
}

Player::~Player() {
}

int Player::useSkill(int index) {
	return 0;
}

int Player::useItem(int index) {
	return 0;
}



std::string Player::getNonBasicInfo(std::ostream& ost) const {
	int count = 0;
	std::ostringstream ostr;
	ostr << "Equipped Skills:" << std::endl;
	ostr.width(30);
	//could use an extract method thing here
	int i;
	for(i = 0; i < _equippedSkills.size(); i++){
		ostr << _equippedSkills[i];
		if(i % 4 == 0){
			ostr << std::endl;
		}
	}
	if(i % 5 != 0){
		ostr << std::endl;
	}
	
	ostr << std::endl;
	ostr.width(0);
	ostr << "Possessed Skills: " << std::endl;
	ostr.width(30);
	for(i = 0; i < _skills.size(); i++){
		ostr << _skills[i];
		if(i % 4 == 0){
			ostr << std::endl;
		}
	}
	if(i % 5 != 0){
		ostr << std::endl;
	}
	ostr << std::endl;
	return ostr.str();
}