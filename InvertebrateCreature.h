#ifndef INVERTEBRATECREATURE_H
#define INVERTEBRATECREATURE_H

#include "SeaCreature.h"

class InvertebrateCreature : public SeaCreature {
public:
    InvertebrateCreature(string name, float size, string type, bool carryingEggs)
        : SeaCreature(name, size, type, carryingEggs, false) {}

    void displayInfo() const override {
    cout << "Invertebrate Creature - " << getName() << endl;
    cout << "Size: " << getSize() << endl;
    cout << "Type: " << getType() << endl;
    cout << "Carrying eggs: " << (getIsCarryingEgg() ? "Yes" : "No") << endl;
    cout << "Has Backbone: " << (getHasBackbone() ? "Yes" : "No") << endl;
}
};

#endif
