#ifndef BAGCHECKER_H
#define BAGCHECKER_H

#include "Bag.h"
#include "UniversalSeaChecker.h"
#include <iostream>
#include <map>
#include <set>
#include <string>

class BagChecker {
private:
	UniversalSeaChecker* checker; // the creature should be legal to keep first before checking the limit
	map<string, int> bagLimit{
		{"bream", 1},
		{"tarwhine", 2},
		{"mahi mahi", 3},
		{"eel", 10},
		{"tarwhine", 4},
		{"lobster", 6},
		{"abalone", 7}
	};

public:

	BagChecker(UniversalSeaChecker* checker) : checker(checker) {}

	bool isBagValid(const Bag &bag) const {
		bool valid = true;

		// check if regulated
		for (auto creature : bag.getCreatures()) {
			if (!checker->isLegalToKeep(creature)) {
				// even the creature is not regulated, if it is not carrying eggs, we can still keep it for now for the check.
				if (creature->getIsCarryingEgg()) {
					valid = false;
					cout << "Creature carrying eggs is not permitted" << endl;
					break;
				}
			}
		}

		// check with bag limits
		if (valid) {
			set<string> speciesSet;
			for (auto creature :bag.getCreatures()) {
				speciesSet.insert(creature->getType());
			}

			for (const auto &species : speciesSet) {
				int count = bag.countSpecies(species);

				// apply a regulated limit if found
				if (bagLimit.find(species) != bagLimit.end()) {
					if (count > bagLimit.at(species)) {
						cout << "Number of allowed " << species << " exceeds limit of " << bagLimit.at(species) << endl;
						valid = false;
					}
				}

				// unregulated creatures checked with limit of 2
				else {
					if (count > 2) {
						cout << "Number of allowed " << species << " exceeds limit of 2."<< endl;
						valid = false;
					}
				}

			}
		}
		return valid;
	}
};

#endif