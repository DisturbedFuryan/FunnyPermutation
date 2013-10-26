#include <iostream>
#include <cstdlib>

#include <iostream>
#include <limits>
#include <string>
#include "App.hpp"
#include "Utility.hpp"

using namespace std;

int main(int argc, char** argv) {
    cout << endl;
    
    /* Getting parameters from user. */
    
    // Getting sequence length.
    unsigned sequenceLength = IUtility::getUnsigned("Type sequence length: ");
    
    // Choosing algorithm to use.
    unsigned short choice = IUtility::getUnsignedShort("Type algorithm to use\n  1 - SteinhausJohnsonTrotter\n  2 - ReverseUse\n> ");
    CApp::AlgorithmType algorithmToUse;
    switch (choice) {
        case 1: 
            algorithmToUse = CApp::SteinhausJohnsonTrotter;
            break;
        
        case 2: 
            algorithmToUse = CApp::ReverseUse;
            break;
                
        default:
            algorithmToUse = CApp::SteinhausJohnsonTrotter;
            break;
    }
    
    // Getting permission for print an algorithm in action.
    string printRunning = "no";
    if (algorithmToUse != CApp::ReverseUse) {
        cout << "Print how algorithm works? ('yes' or 'no'): ";
        cin >> printRunning; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }
    
    // Getting permission for print permutations.
    string printPermutations = "no";
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
