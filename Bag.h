#ifndef BAG_H
#define BAG_H

#include "SeaCreature.h"   
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Bag {
private:
    // collection of SeaCreature objs
    vector<SeaCreature*> creatures;  

public:
    // destructor to clean up dynamic allocations
    ~Bag() {
        for (auto c : creatures) {
            delete c;
        }
    }

    // add a creature to the bag.
    void addCreature(SeaCreature* creature) {
        creatures.push_back(creature);
    }

    // gets a constant reference to vector of SeaCreature pointers.
    const vector<SeaCreature*>& getCreatures() const {
        return creatures;
    }

    // count the number of creatures of a given species.
    int countSpecies(const string &species) const {
        return count_if(creatures.begin(), creatures.end(), [&](SeaCreature* creature) {
            return creature->getType() == species;
        });
    }

    void displayContents() const {
        cout << "Bag Contents:" << endl;
        for (size_t i = 0; i < creatures.size(); ++i) {
            cout << i + 1 << ". ";
            creatures[i]->displayInfo();  
            cout << endl;
        }
    }
};

#endif
