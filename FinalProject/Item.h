#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
private:
    string name;
    double monetaryCost;
    int charismaCost;
    bool acquired;

public:
    bool isSuit;
    Item(std::string n, double m, int c, bool a, bool b); //constructor

    bool attemptAcquire(double playerMoney, int playerCharisma);
    
    std::string getName();
    double getMonetaryCost();
    int getCharismaCost();
    bool getAcquired();
    void setAcquired(bool a);
};

#endif