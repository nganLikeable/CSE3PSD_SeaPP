// because the process of checking is the same for 2 types => one unified checker

#ifndef UNIVERSALSEACHECKER_H
#define UNIVERSALSEACHECKER_H

#include "SeaChecker.h"
#include <map>
#include <string>

class UniversalSeaChecker : public SeaChecker {
private:
    map<string, float> sizeRules;

public:
    UniversalSeaChecker(const map<string, float>& rules) : sizeRules(rules) {}    
    
    // check for regulation existence before checking if legal to keep
    bool isLegalToKeep(SeaCreature* creature) const override {
             return creature->getSize() >= sizeRules.at(creature->getType()) 
           && !creature->getIsCarryingEgg();

    }
    
    bool hasRegulation(const string& type) const override {
        auto it = sizeRules.find(type);
        if (it == sizeRules.end()) {
            cout << "No regulations found for this type: " << type << endl;
            return false;
        }
     return true;
    }
};
#endif

