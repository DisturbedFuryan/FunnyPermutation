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
}
