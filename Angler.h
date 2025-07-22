#ifndef ANGLER_H
#define ANGLER_H

#include "Bag.h"
#include "SeaCreature.h"
#include <string>

class Angler {
private:
    string name;
    Bag bag;

public:
    Angler(string name) : name(name) {};
    
    string getName() const { 
        return name; 
    }
    
    void catchCreature(SeaCreature* creature) {
        bag.addCreature(creature);
    }
    
    // non-const instance
    Bag& getBag() {
        return bag;
    }
    // const instance that can be called on const angler objs
    const Bag& getBag() const {
        return bag;
    }
};

#endif
