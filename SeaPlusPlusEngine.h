#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include "SeaCreature.h"
#include "UniversalSeaChecker.h"
#include "ConcreteSeaCreatureFactory.h"
#include <map>
#include <string>
#include "BagChecker.h"
#include "Angler.h"

// central point for coordination
class SeaPlusPlusEngine {
private:
    UniversalSeaChecker* checker;
    ConcreteSeaCreatureFactory* factory; 
    BagChecker* bagChecker;

public:
	SeaPlusPlusEngine() {
		map<string, float> sizeRules = {
		    {"bream", 25}, 
    		{"tarwhine", 20}, 
    		{"flathead", 25}, 
    		{"red morwong", 30},
    		{"abalone", 11.7}, 
    		{"balmain bug", 10},
    		{"mud crab", 9.3},
    		{"spanner crab", 9.3}, 
    		{"lobster", 10.4}};
		checker = new UniversalSeaChecker(sizeRules);
		factory = new ConcreteSeaCreatureFactory();
		bagChecker = new BagChecker(checker);
	}

	~SeaPlusPlusEngine() {
		delete checker;
		delete factory;
		delete bagChecker;
	}

	bool isTypeRegulated(const string& type) {
		return checker->hasRegulation(type);
	}

	bool checkCreature(SeaCreature* creature) {
		return checker->isLegalToKeep(creature);
	}
	
	SeaCreature* createSeaCreature(const string& name, float size, const string& type, bool carryingEggs) {
	    return factory->createCreature( name,  size,  type,  carryingEggs);
	};

	
	bool validateBag(const Angler& angler) const {
        return bagChecker->isBagValid(angler.getBag());	}
};

#endif
