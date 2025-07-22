#ifndef VERTEBRATECREATURE_H
#define VERTEBRATECREATURE_H

#include "SeaCreature.h"

class VertebrateCreature : public SeaCreature {
public:
    VertebrateCreature(string name, float size, string type, bool carryingEggs)
        : SeaCreature(name, size, type, carryingEggs, true) {}

    void displayInfo() const override {
        cout << "Vertebrate Creature - " << getName() << endl;
        cout << "Size: " << getSize() << endl;
        cout << "Type: " << getType() << endl;
        cout << "Carrying eggs: " << (getIsCarryingEgg() ? "Yes" : "No") << endl;
        cout << "Has Backbone: " << (getHasBackbone() ? "Yes" : "No") << endl;
    }
};

#endif
