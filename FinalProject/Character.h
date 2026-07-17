#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character {
private:
    string location; // two variables
    string dialogue;

public:
    string name;
    bool interacted;

    Character() : location("congress"), dialogue("Hello!"), name("Bob"), interacted(false) {} // default

    Character(std::string l, std::string n, string d, bool i) { //parametrized
        location = l;
        name = n;
        dialogue = d;
        interacted = i;
    }

    string getCharName();
    string getCharLocation();
    void talkToChar();
    void buyFromChar(int z); // z is a placeholder
};

#endif