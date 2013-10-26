#include <iostream>
#include "Algorithm.hpp"
#include "App.hpp"
#include "Bmu.hpp"
#include "Parameters.hpp"
#include "ReverseUse.hpp"
#include "singletons.hpp"
#include "Sequence.hpp"
#include "SteinhausJohnsonTrotter.hpp"
#include "Utility.hpp"

CApp::CApp(const unsigned sequenceLength, const AlgorithmType algorithmToUse) {
    switch (algorithmToUse) {
        case SteinhausJohnsonTrotter:
            m_algorithm = new CSteinhausJohnsonTrotter(sequenceLength, &m_permutations);
            break;
            
        case ReverseUse:
            m_algorithm = new CReverseUse(sequenceLength, &m_permutations);
            break;

        case Bmu:
            m_algorithm = new CBmu(sequenceLength, &m_permutations, g_parameters.recursiveSearch());
            break;
    }
}

CApp::~CApp() {
    delete m_algorithm;
    
    vector<CSequence*>::iterator it;
    for (it = m_permutations.begin(); it != m_permutations.end(); ++it) {
        delete *it;
    }
}

unsigned CApp::findPermutations(const bool showRunning) {
    return m_algorithm->findPermutations(showRunning);
}
    
void CApp::printPermutations() const {
    {
        unsigned permutationNumber = 1;
        vector<CSequence*>::const_iterator it;
        for (it = m_permutations.begin(); it != m_permutations.end(); ++it, ++permutationNumber) {
            IUtility::printAdditionalZeros(permutationNumber, 5);
            cout << permutationNumber << ":  ";
            (*it)->print();
            cout << endl;
        }
    }
    
    cout << endl;
}

bool CApp::validation() const {
    if (m_permutations.empty()) {
        return false;
    }
    
    {
        vector<CSequence*>::const_iterator itI, itJ;
        for (itI = m_permutations.begin(); itI != m_permutations.end(); ++itI) {
            for (itJ = m_permutations.begin(); itJ != m_permutations.end(); ++itJ) {
                if ((itI != itJ) && (**itI == **itJ)) {
                    return false;
                }
            }
        }
    }
    
    return true;
}
