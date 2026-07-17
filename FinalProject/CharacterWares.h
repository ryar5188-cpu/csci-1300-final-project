

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

class Wares : public Character {
private:
    int numOfWares;
public:
    string wareDescription;
    string wareName;
    int wareValue;
    vector<string> wares = {};

    Wares() : numOfWares(1), wareDescription("this is a thing"), wareName("name goes here"), wareValue(200) {}

    Wares(int p, string d, string n, int v) : Character() {
        numOfWares = p;
        wareDescription = d;
        wareName = n;
        wareValue = v;

        wares.push_back(wareName);
    }

    int checkWares();
    void listWares();
    void buy();
};


