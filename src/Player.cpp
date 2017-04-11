/*
File:     Player.cpp
Purpose:  Implementation for Player.h
*/

#include "Player.h"
typedef unsigned int uint;

// The default constructor creates a Player object that 'NULL' for all member
// variables except 'decs' which is set to 0.
Player::Player() {
    uint decs = 0;
    std::string name = NULL;
    Node pos = NULL;
    std::map< std::string, uint > = NULL;
}

Player::Player(std::string aName, Node aPos) {
    uint decs = 0;
    std::string name = aName;
    Node pos = aPos;
    // This line is not correct, but it won't return an error if called.
    std::map< std::string, uint > skills = NULL;
}

// ----------------------------------------------------------------
// ACCESSORS

uint Player::get_decs() const {
    return decs;
}

std::string Player::get_name() const {
    return name;
}

Node Player::get_pos() const {
    return pos;
}

std::map< std::string, uint > Player::get_skills() const {
    return skills;
}

// ----------------------------------------------------------------
// MODIFIERS

void Player::mod_code(int mod) {
    // skills["Coding"] += mod;
}

void Player::mod_team(int mod) {
    // skills["Teamwork"] += mod;
}

void Player::mod_vc(int mod) {
    // skills["Version Control"] += mod;
}

// ----------------------------------------------------------------
// MEMBER FUNCTIONS

bool Player::traverse(Node newPos) {
    added = false;
    return added;
}
