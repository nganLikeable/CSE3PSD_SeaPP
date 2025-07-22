// abstract factory

#ifndef SEACREATUREFACTORY_H
#define SEACREATUREFACTORY_H

#include "SeaCreature.h"
using namespace std;

class SeaCreatureFactory {
public:
    virtual ~SeaCreatureFactory() = default;
    virtual SeaCreature* createCreature(string name, float size, string type, bool carryingEggs) = 0;
};

#endif
