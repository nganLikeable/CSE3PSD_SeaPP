#include "SeaPlusPlusApp.h"

int main() {
    string firstUser;
    cout << "Enter your name: ";
    cin >> firstUser;
    
    SeaPlusPlusApp app(firstUser);
    app.run();
    
    return 0;
}
