#ifndef SENATOR_H
#define SENATOR_H
#include <string>
#include "Poli.h"
using namespace std;
class Senator : public Poli {
    public:
        double multiplier;
        double extraRarity;
    private:
        Senator(double multiplier, double extraRarity);
};
#endif