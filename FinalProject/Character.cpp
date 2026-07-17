#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

string Character::getCharName() {
    return name;
}

string Character::getCharLocation() {
    return location;
}

void Character::talkToChar() {
    if (interacted == false) {
        cout << name << " >> '" << dialogue << "'" << endl;
        interacted = true;
    }
    else {
        cout << name << " >> 'I have already talked with you, have a good day.'" << endl;
    }
}

void Character::buyFromChar(int z) {} // for future expansion