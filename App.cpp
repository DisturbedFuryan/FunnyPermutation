#include "App.h"

CApp::CApp(const unsigned sequenceLength, const AlgorithmType algorithmToUse) {
    switch (algorithmToUse) {
        case SteinhausJohnsonTrotter:
            m_algorithm = new CSteinhausJohnsonTrotter(sequenceLength, &m_permutations);
            break;
    }
}

CApp::~CApp() {
    delete m_algorithm;
    
    for (vector<CSequence*>::iterator it = m_permutations.begin(); it != m_permutations.end(); ++it) {
        delete *it;
    }
}

unsigned CApp::findPermutations(const bool showRunning) {
    return m_algorithm->findPermutations(showRunning);
}
    
void CApp::printPermutations() const {
    for (vector<CSequence*>::const_iterator it = m_permutations.begin(); it != m_permutations.end(); ++it) {
        (*it)->print(); cout << endl;
    }
    cout << endl;
}

bool CApp::validation() const {
    for (vector<CSequence*>::const_iterator itI = m_permutations.begin(); itI != m_permutations.end(); ++itI) {
        for (vector<CSequence*>::const_iterator itJ = m_permutations.begin(); itJ != m_permutations.end(); ++itJ) {
            if ((itI != itJ) && (**itI == **itJ)) {
                return false;
            }
        }
    }
    
    return true;
}
