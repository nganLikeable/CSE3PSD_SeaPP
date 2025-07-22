#ifndef ANGLERMANAGER_H
#define ANGLERMANAGER_H

#include "Angler.h"
#include <map>

// store angler names with the references to Angler objs
class AnglerManager {
private:
    map<string, Angler*> anglers;

public:
    // free allocated memory
    ~AnglerManager() {
        for (auto& pair : anglers) {
            delete pair.second;
        }
    }
    
    // add new angler
    void addAngler(const string& name) {
        if (anglers.find(name) == anglers.end()) {
            anglers[name] = new Angler(name);
            cout << "Angler " << name << " added." << endl;
        } else {
            cout << "Angler " << name << " already exists." << endl;
        }
    }

    Angler* getAngler(const string& name) {
        auto it = anglers.find(name);
        if (it != anglers.end()) {
            return it->second;
        }
        cout << "Angler " << name << " not found." << endl;
        return nullptr; 
    }
    
    void saveBag(const string& anglerName, const Bag& bag) {
        Angler* angler = getAngler(anglerName);
        // if angler exists
        if (angler) {
            angler->getBag() = bag;
            cout << "Bag saved for Angler: " << anglerName << endl;
        }
    }
    };

#endif
