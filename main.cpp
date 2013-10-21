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
    
    // Getting permission for print an algoritm in action.
    string printRunning;
    cout << "Print how algorithm works? ('yes' or 'no'): "; cin >> printRunning; cout << endl;
    
    // Getting permission for print permutations.
    string printPermutations;
    cout << "Print permutations? ('yes' or 'no'): "; cin >> printPermutations; cout << endl;
    
    /* Creating object of CApp class with parameters given above. */
    CApp app(sequenceLength, algorithmToUse);
    
    /* Finding permutations. */
    cout << "Number of found permutations: " << app.findPermutations((printRunning == "yes") ? true : false) << endl << endl;
    
    /* Printing permutations. */
    if (printPermutations == "yes") app.printPermutations();
    
    /* Validation. */
    cout << "Validation: " << (app.validation() ? "SUCCESS" : "FAILURE") << endl << endl; 
    
    return EXIT_SUCCESS;
}
