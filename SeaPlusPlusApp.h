#ifndef SEAPLUSPLUSAPP_H
#define SEAPLUSPLUSAPP_H

#include "SeaPlusPlusEngine.h"
#include "AnglerManager.h"
#include <iostream>
#include <string>
using namespace std;

class SeaPlusPlusApp {
private:
	SeaPlusPlusEngine* mediator;
	Angler* angler;
	AnglerManager* anglerManager;
	string activeAngler; // current user

public:
	SeaPlusPlusApp(string firstUser) {
		mediator = new SeaPlusPlusEngine();
		anglerManager = new AnglerManager();
		activeAngler = firstUser;
		anglerManager->addAngler(activeAngler);
		angler = anglerManager->getAngler(activeAngler); // initialize the angler pointer

	}

	~SeaPlusPlusApp() {
		delete mediator;
		delete anglerManager;
	}

	void run() {
		cout << "Welcome to Sea++! Hello, " << angler->getName() << endl;
		string choice;

		while (true) {
		    cout << "--------------------------" << endl;
			cout << "Options:" << endl;
			cout << "1. Switch Angler" <<endl;
			cout << "2. Enter a SeaCreature" << endl;
			cout << "3. Validate Bag" << endl;
			cout << "4. Save Bag" << endl;
			cout << "5. Display Bag" << endl;
			cout << "6. Quit" << endl;
			cout << "Choice: ";
			cin >> choice;
			cout << endl;

			if (choice == "6") {
				cout << "Goodbye!" << endl;
				break;
			}

			else if (choice == "1") {
				string newAngler;
				cout << "Enter Angler name: ";
				cin >> newAngler;
				anglerManager->addAngler(newAngler);
				activeAngler = newAngler;
				angler = anglerManager->getAngler(activeAngler); // update pointer; otherwise it would store the wrong bag
				cout << "You are now logged in as: " << newAngler << endl;
			}

			else if (choice == "2") {
				string name, type;
				float size = 0;
				bool carryingEggs = false;

				cout << "Enter creature name: ";
				cin >> name;
				cout << "Enter creature type: ";
				cin.ignore();
				getline(cin,type); // the program crashes when using cin>>type only as it only reads 1 word from type(mud instead of mud crab)

				// if the type is regulated, ask for additional details.
				if (mediator->isTypeRegulated(type)) {
					cout << "Enter creature size: ";
					cin >> size;
					cout << "Is the creature carrying eggs? (1 = Yes, 0 = No): ";
					cin >> carryingEggs;
				}
				// if not regulated => continue without performing any further action - restart the loop
				else {
					continue;
				}

				SeaCreature* creature = mediator->createSeaCreature(name, size, type, carryingEggs);
				cout << endl;
				creature->displayInfo();
				cout << endl;

				// perform the individual creature check
				if (mediator->checkCreature(creature)) {
					cout << "You can keep this creature!" << endl;
					angler->catchCreature(creature); // add to bag
					cout << "Creature added to your bag." << endl;
				} else {
					cout << "You must return this creature to the sea." << endl;
					delete creature; // prvent memory leak
				}
			}
			// validate bag
			else if (choice == "3") {
				// validate the angler's entire bag
				if (mediator->validateBag(*angler)) {
					cout << "Your bag is valid." << endl;
				} else {
					cout << "Your bag is not valid." << endl;
				}
				cout << endl;
			}
			// save associated bag
			else if (choice == "4") {
				anglerManager->saveBag(activeAngler, angler->getBag());
			}
			else if (choice == "5") {
				angler->getBag().displayContents();
			}
			else {
				cout << "Invalid choice. Please try again." << endl;
			}
		}
	}
};

#endif
