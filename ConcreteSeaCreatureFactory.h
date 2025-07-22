// concrete factory
// check for types and create the creature accordingly
#ifndef CONCRETESEACREATUREFACTORY_H
#define CONCRETESEACREATUREFACTORY_H

#include "SeaCreatureFactory.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"
#include <set>

class ConcreteSeaCreatureFactory : public SeaCreatureFactory {
public:
    SeaCreature* createCreature(string name, float size, string type, bool carryingEggs) override {
        set<string> invertebrateSet = {"abalone", "balmain bug", "mud crab", "spanner crab", "lobster"};

        if (invertebrateSet.find(type) != invertebrateSet.end()) {
            return new InvertebrateCreature(name, size, type, carryingEggs);
        } else {
            return new VertebrateCreature(name, size, type, carryingEggs);
        }
    }
};  

#endif  
