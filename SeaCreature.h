#ifndef SEACREATURE_H
#define SEACREATURE_H

#include <string>
#include <iostream>
using namespace std;

class SeaCreature {
private:
    string name;
    float size;
    bool carryingEggs;
    string type;
    bool hasBackbone;

public:
    SeaCreature(string name, float size, string type, bool carryingEggs, bool hasBackbone)
        : name(name), size(size), type(type), carryingEggs(carryingEggs), hasBackbone(hasBackbone) {}

    string getName() const { return name; }
    float getSize() const { return size; }
    bool getIsCarryingEgg() const { return carryingEggs; }
    string getType() const { return type; }
    bool getHasBackbone() const { return hasBackbone; }

    virtual void displayInfo() const = 0;
};

#endif
