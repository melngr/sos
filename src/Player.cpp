/*
 * Player.cpp
 *
 * contains implementations for Player specific functions
 * Player objects can use Item or use Skill objects
 */

#include <string>
#include <sstream>
#include <iomanip>
#include "Player.h"
#include "Utilities.h"

//Player class: stores the player's name and Entity attributes
Player::Player(std::string name) : Entity(name) {
	_stamina = 100;
	_startingStamina = _stamina;
	_attack = 2;
	_defense = 0;
	learnSkill("Hack Solution", 99999);
}

Player::~Player() {
	for(unsigned int i = 0; i < _skills.size(); i++){
		delete _skills[i];
	}
}

//instruct the player to use the skill specified by input index
int Player::useSkill(int index) {
	Skill* chosenSkill = _skills[index];
	return chosenSkill->use(_attack);
}

//instruct the player to use the item specified by input index
int Player::useItem(int index) {
	return 0;
}

//return the index of the skill named skillName, or -1 if the player does not possess that skill
int Player::skillIndex(std::string skillName) {
	int i = 0;
	for (std::vector<Skill*>::iterator itr = _skills.begin(); itr != _skills.end(); ++itr, ++i) {
		if (equalsIgnoreCase((*itr)->getName(),skillName)) {
			return i;
		}
	}
	return -1;
}

//compile a string of advanced Player class information
std::string Player::getNonBasicInfo(std::ostream& ost) const {
	int colWidth = 15;
	//int count = 0;
	std::ostringstream ostr;
	ostr << "Equipped Skills:" << std::endl;
	//could use an extract method thing here
	unsigned int i;
	for(i = 0; i < _equippedSkills.size(); i++){
		ostr << std::setw(colWidth) << *(_equippedSkills[i]) << std::setw(colWidth);
		if( (i != 0 && i%4 == 0) || (i % 3 == 0 && i == 0) ){
			ostr << std::endl;
		}
	}
	if(i % 5 != 0){
		ostr << std::endl;
	}
	
	ostr << std::endl;
	ostr.width(0);
	ostr << "Possessed Skills: " << std::endl;
	for(i = 0; i < _skills.size(); i++){
		ostr << std::setw(colWidth) << std::left <<  *(_skills[i]) << std::setw(colWidth);
		if( (i != 0 && i%4 == 0) || (i % 3 == 0 && i == 0) ){
			ostr << std::endl;
		}
	}
	if(i % 5 != 0){
		ostr << std::endl;
	}
	ostr << std::endl;
	return ostr.str();
}
