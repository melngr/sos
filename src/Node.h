/*
File:     Node.h
Purpose:  This is the header file for the Node class. This node is designed to
          better store information about the connections through the sos_list.
*/

#include <map>
#include <string>

typedef unsigned int uint;

// ----------------------------------------------------------------

class Node {
public:
    Node();

// ----------------------------------------------------------------
// ACCESSORS

    std::string get_description() const;
    std::map< std::string, int > get_mods() const;
    // Node[] get_next() const;
    Node get_prev() const;

// ----------------------------------------------------------------
// MODIFIERS

    void set_description(std::string aDescription);
    void set_mods(std::map< std::string, int > aMods);
    // void set_next(Node[] aNext);
    void set_prev(Node aPrev);

// ----------------------------------------------------------------
// MEMBER FUNCTIONS

    void activate();


// ----------------------------------------------------------------
// ----------------------------------------------------------------


private:
    std::string description;
    std::map< std::string, int > mods;
    // Node[] next;
    Node prev;
} ;
