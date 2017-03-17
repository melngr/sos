/*
File:     Player.h
Purpose:  This is the header file for the Player class. This is a class that will
          store information about a player inherited by the user that can
          have skills and stats change based on decision path taken by the user.
*/

#include <map>
#include <string>
#include "Node.h"

typedef unsigned int uint;

// ----------------------------------------------------------------

class Player {
public:
    Player(std::string name);

// ----------------------------------------------------------------
// ACCESSORS

    uint get_decs() const;
    std::string get_name() const;
    Node get_pos() const;
    std::map< std::string, uint > get_skills() const;

// ----------------------------------------------------------------
// MODIFIERS

    /* void set_code(int mod);  // set 'Coding' skill
    void set_team(int mod);  // set 'Teamwork' skill
    void set_vc(int mod);    // set 'Version Control' skill */

    void mod_code(int mod);  // change 'Coding' skill
    void mod_team(int mod);  // change 'Teamwork' skill
    void mod_vc(int mod);    // change 'Version Control' skill

// ----------------------------------------------------------------
// MEMBER FUNCTIONS

    void traverse(Node new_pos);


// ----------------------------------------------------------------
// ----------------------------------------------------------------


private:
    uint decs;
    std::string name;
    Node pos;
    std::map< std::string, uint > skills;
} ;
