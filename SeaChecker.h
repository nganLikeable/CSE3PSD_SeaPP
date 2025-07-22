// Abstract base class 

#ifndef SEACHECKER_H
#define SEACHECKER_H

#include "SeaCreature.h"
using namespace std;

class SeaChecker {
public:
    virtual ~SeaChecker() = default;
    virtual bool isLegalToKeep(SeaCreature* creature) const = 0;
    virtual bool hasRegulation(const std::string& type) const = 0; 
};

#endif
