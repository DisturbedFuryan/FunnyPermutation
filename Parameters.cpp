#include <iostream>
#include <limits>
#include <string>
#include "Parameters.hpp"
#include "Utility.hpp"

using namespace std;

CParameters::CParameters() : m_sequenceLength(3), m_printWorkingAlgorithm(true),
                             m_printPermutations(true), m_recursiveSearch(false) {
    m_algorithmType = CApp::SteinhausJohnsonTrotter;
}

void CParameters::getParametersFromUser() {
    m_sequenceLength = getSequenceLengthFromUser();
    m_algorithmType = getAlgorithmTypeFromUser();

    if (m_algorithmType == CApp::Bmu) {
        // Only the Bmu algorithm has the two ways of search.
        m_recursiveSearch = getPermissionForRecursiveSearch();
    }

    m_printWorkingAlgorithm = getPermissionForPrintWorkingAlgorithm();
    m_printPermutations = getPermissionForPrintPermutations();
}

unsigned CParameters::getSequenceLengthFromUser() const {
    return IUtility::getUnsigned("Type sequence length: ");
}

CApp::AlgorithmType CParameters::getAlgorithmTypeFromUser() const {
    unsigned short choice = IUtility::getUnsignedShort("Type algorithm to use\n"
                                                       "  1 - SteinhausJohnsonTrotter\n"
                                                       "  2 - ReverseUse\n"
                                                       "  3 - Bmu\n> ");
    switch (choice) {
        case 1: 
            return CApp::SteinhausJohnsonTrotter;
        
        case 2: 
            return CApp::ReverseUse;
        
        case 3:
            return CApp::Bmu;

        default:
            return CApp::SteinhausJohnsonTrotter;
    }
}

bool CParameters::getPermissionForPrintWorkingAlgorithm() const {
    string printRunning = "no";
    cout << "Print how algorithm works? ('yes' or 'no'): ";
    cin >> printRunning;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    return (printRunning == "yes");
}

bool CParameters::getPermissionForPrintPermutations() const {
    string printPermutations = "no";
    cout << "Print permutations? ('yes' or 'no'): ";
    cin >> printPermutations;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    return (printPermutations == "yes");
}

bool CParameters::getPermissionForRecursiveSearch() const {
    string recursiveSearch = "no";
    cout << "Use recursive search? ('yes' or 'no'): ";
    cin >> recursiveSearch;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    return (recursiveSearch == "yes");
}
