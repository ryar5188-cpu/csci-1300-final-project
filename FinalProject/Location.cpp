#include "Location.h"
#include <iostream>

Location::Location() : name("Unknown Location") {} //default

Location::Location(std::string locName) : name(locName) {} //parametrized

std::string Location::getName() const {
    return name;
}

void Location::printBanner() const {
    std::cout << "====================================" << std::endl;
    std::cout << "         " << name << std::endl;
    std::cout << "====================================" << std::endl;
}

void Location::printInteractionOptions() const { // what the player interacts with in each unique location.
    std::cout << "Choose one:" << std::endl;
    
    if (name == "Square") {
        std::cout << "PRESS A: Talk to Insider Bill" << std::endl;
        std::cout << "PRESS B: Talk to Agent Bob" << std::endl;
        std::cout << "PRESS C (+1 turn): Go to Congress" << std::endl;
        std::cout << "PRESS D (+1 turn): Go to Cramped Apartment" << std::endl;
    } 
    else if (name == "White House") {
        std::cout << "PRESS A (-50 Charisma): Obtain a pardon from the president" << std::endl;
        std::cout << "PRESS B (+1 turn): Go to Congress" << std::endl;
    } 
    else if (name == "Congress") {
        std::cout << "PRESS A: Talk to Congressperson Rick" << std::endl;
        std::cout << "PRESS B: Talk to Congressperson Jessica" << std::endl;
        std::cout << "PRESS C: Talk to Congressperson Seth" << std::endl;
        std::cout << "PRESS D (+1 turn): Go to Supreme Court" << std::endl;
        std::cout << "PRESS E (+1 turn): Go to White House" << std::endl;
        std::cout << "PRESS F (+1 turn): Go to D.C. Main Square" << std::endl;
    } 
    else if (name == "Supreme Court") {
        std::cout << "PRESS A: Talk to the Chief Justice" << std::endl;
        std::cout << "PRESS B (-100 Charisma, +1 Lucky Gavel): Successfully argue to the Chief Justice that you should own his Lucky Gavel" << std::endl;
        std::cout << "PRESS C (+1 turn): Go to Cramped Apartment" << std::endl;
        std::cout << "PRESS D (+1 turn): Go to Congress" << std::endl;
    } 
    else if (name == "Cramped Apartment") {
        std::cout << "PRESS A: View your wardrobe" << std::endl;
        std::cout << "PRESS B: Admire your shelf" << std::endl;
        std::cout << "PRESS C: Open your safe" << std::endl;
        std::cout << "PRESS D (+1 turn): Go to Shady Alley" << std::endl;
        std::cout << "PRESS E (+1 turn): Go to D.C. Main Square" << std::endl;
        std::cout << "PRESS F (+1 turn): Go to Supreme Court" << std::endl;
    } 
    else if (name == "Shady Alley") {
        std::cout << "PRESS A (-$100, +25 Charisma points): Buy suit with blue tie" << std::endl;
        std::cout << "PRESS B (-$500, +150 Charisma points): Buy suit with red tie" << std::endl;
        std::cout << "PRESS C (-$1000, +1 Ancient D.C. artifact): Buy a piece of rock with odd engravings" << std::endl;
        std::cout << "PRESS D (+1 turn): Go to Cramped Apartment" << std::endl;
    }
}