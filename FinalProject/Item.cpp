#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string n, double m, int c, bool a, bool b){
    name = n;
    monetaryCost = m;
    charismaCost = c;
    acquired = a;
    isSuit = b;
}


bool Item::attemptAcquire(double playerMoney, int playerCharisma) { //checks if the player can actually afford to purchase the item.
    if (playerMoney >= monetaryCost && playerCharisma >= charismaCost) {
        acquired = true;
        return true;
    }
    return false;
}

string Item::getName() {
    return name;
}

double Item::getMonetaryCost() {
    return monetaryCost;
}

int Item::getCharismaCost() {
    return charismaCost;
}

bool Item::getAcquired() {
    return acquired;
}

void Item::setAcquired(bool a) {
    acquired = a;
}