#ifndef LOCATION_H
#define LOCATION_H
#include <string>
using namespace std;

class Location {
private:
    string name;
public:
    Location();
    Location(string locName);

    string getName() const;

    void printBanner() const;
    void printInteractionOptions() const;
};

#endif