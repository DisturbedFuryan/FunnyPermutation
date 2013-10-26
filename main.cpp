#include <cstdlib>
#include <iostream>
#include "App.hpp"
#include "Parameters.hpp"

using namespace std;

int main(int argc, char** argv) {
    cout << endl;
    
    /* Getting parameters from user. */
    CParameters parameters;
    parameters.getParametersFromUser();
    
    /* Creating object of CApp class with given parameters. */
    CApp app(parameters.sequenceLength(), parameters.algorithmType());
    
    /* Finding permutations and printing number of found. */
    cout << "Number of found permutations: " 
         << app.findPermutations(parameters.printWorkingAlgorithm()) << endl << endl;
    
    /* Printing permutations. */
    if (parameters.printPermutations()) {
        app.printPermutations();
    }
    
    /* Validation. */
    cout << "Validation: " << (app.validation() ? "SUCCESS" : "FAILURE") << endl << endl; 
    
    return EXIT_SUCCESS;
}
