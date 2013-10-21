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

const unsigned CApp::findPermutations(const bool showRunning) {
    return m_algorithm->findPermutations(showRunning);
}
    
void CApp::printPermutations() const {
    for (vector<CSequence*>::const_iterator it = m_permutations.begin(); it != m_permutations.end(); ++it) {
        (*it)->print(); cout << endl;
    }
    cout << endl;
}
