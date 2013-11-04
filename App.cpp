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

    cout << "Validating";  // Behind this the dots will be printed.
    
    {
        float progress;  // Progress in percentage.
        const unsigned permNum = m_permutations.size();  // Number of found permutations.
        short dotsNumToPrint, printedDotsNum = 0;

        vector<CSequence*>::const_iterator itI, itJ;
        for (itI = m_permutations.begin(); itI != m_permutations.end(); ++itI) {
            for (itJ = m_permutations.begin(); itJ != m_permutations.end(); ++itJ) {
                /* Progress bar. */
                progress = ((((static_cast<float>(distance(m_permutations.begin(), itI)) * permNum)
                            + distance(m_permutations.begin(), itJ)) / (permNum * permNum)) * 100);

                dotsNumToPrint = (static_cast<short>(progress) / 10);

                // Printing the dots.
                for (short s = 0; s < (dotsNumToPrint - printedDotsNum); ++s) {
                    cout << '.';
                }
                cout.flush();

                printedDotsNum = dotsNumToPrint;

                /* Validation. */
                if ((itI != itJ) && (**itI == **itJ)) {
                    return false;
                }
            }
        }

        // Printing the rest of dots.
        for (short s = 0; s < (10 - printedDotsNum); ++s) {
            cout << '.';
        }

        cout << endl << endl;
    }
    
    return true;
}
