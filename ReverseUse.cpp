#include <iostream>
#include <iomanip>
#include "ReverseUse.hpp"
#include "Sequence.hpp"

CReverseUse::CReverseUse(const unsigned sequenceLength, vector<CSequence*>* permutations)
                        : IAlgorithm(sequenceLength, permutations) {}

unsigned CReverseUse::findPermutations(const bool showRunning) {
    if (m_sequenceLength == 0) {
        return 0;
    }
    
    CSequence baseSequence(m_sequenceLength);
    baseSequence.fillAscending();
    
    antylex(m_sequenceLength, baseSequence, showRunning);

    if (showRunning) {
        cout << endl;
    }
    
    return m_permutations->size();
}

void CReverseUse::antylex(const unsigned m, CSequence& sequence,
                          const bool showRunning, const unsigned indent) {
    if (m == 0) {
        if (showRunning) {
            cout << "  ";
            sequence.print();
            cout << endl;
        }

        CSequence* sequenceOnList = addSequence();
        *sequenceOnList = sequence;
    }
    else {
        if (showRunning) {
            if (indent) {
                cout << setw(indent) << ' ';
                cout << "\\__";
            }

            cout << "ANTYLEX(" << m << ")";
            
            if (m > 1) {
                cout << endl;
            }
        }

        for (unsigned u = 0; u < m; ++u) {
            antylex((m - 1), sequence, showRunning, (indent + 4));
            
            if (u < (m - 1)) {
                sequence.reverse(m);
            }
        }
    }
}
