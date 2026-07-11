#ifndef REPRESENTATIVE_H
#define REPRESENTATIVE_H
#include <string>
#include "Poli.h"
using namespace std;

class Representative : public Poli {
    public:
        double additive;
        double baseRarity;
    public:
        Representative(double additive, double baseRarity);
};

#endif