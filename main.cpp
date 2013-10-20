#include <iostream>
#include <cstdlib>

#include <iostream>
#include <string>
#include "App.h"

using namespace std;

int main(int argc, char** argv) {
    cout << endl;
    
    /* Getting parameters from user. */
    
    // Getting sequence length.
    unsigned sequenceLength;
    cout << "Type sequence length: "; cin >> sequenceLength; cout << endl;
    
    // Choosing algorithm to use.
    short choice;
    cout << "Type algorithm to use (1 - SteinhausJohnsonTrotter): "; cin >> choice; cout << endl;
    CApp::AlgorithmType algorithmToUse;
    switch (choice) {
        case 1: algorithmToUse = CApp::SteinhausJohnsonTrotter;
                break;
    }
    
    // Getting permission for print permutations.
    string printPermutations;
    cout << "Print permutations? ('yes' or 'no'): "; cin >> printPermutations; cout << endl;
    
    /* Creating object of CApp class with parameters given above. */
    CApp app(sequenceLength, algorithmToUse);
    
    /* Finding permutations. */
    app.findPermutations();
    
    /* Printing permutations. */
    if (printPermutations == "yes") {
        app.printPermutations();
    }
    
    return EXIT_SUCCESS;
}
