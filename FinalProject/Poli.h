#ifndef POLI_H
#define POLI_H
#include <string>
using namespace std;
class Poli {
    private:
        string name;
        string RtL;
        int age;
        string committee;
        string rarity;
    
    public:
        Poli(string n, string leaning, int age, string committee, string rarity);

};
#endif