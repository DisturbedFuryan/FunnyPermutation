#include <iostream>
#include <cstdlib>

#include <iostream>
#include <limits>
#include <string>
#include "App.h"
#include "Utility.h"

using namespace std;

int main(int argc, char** argv) {
    cout << endl;
    
    /* Getting parameters from user. */
    
    // Getting sequence length.
    unsigned sequenceLength = IUtility::getUnsigned("Type sequence length: ");
    
    // Choosing algorithm to use.
    unsigned short choice = IUtility::getUnsignedShort("Type algorithm to use (1 - SteinhausJohnsonTrotter): ");
    CApp::AlgorithmType algorithmToUse;
    switch (choice) {
        case 1: 
            algorithmToUse = CApp::SteinhausJohnsonTrotter;
            break;
                
        default:
            algorithmToUse = CApp::SteinhausJohnsonTrotter;
            break;
    }
    
    // Getting permission for print an algoritm in action.
    string printRunning;
    cout << "Print how algorithm works? ('yes' or 'no'): ";
    cin >> printRunning; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
    // Getting permission for print permutations.
    string printPermutations;
    cout << "Print permutations? ('yes' or 'no'): ";
    cin >> printPermutations; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
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
