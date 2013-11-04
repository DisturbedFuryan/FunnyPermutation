#include <iomanip>
#include <iostream>
#include "ReverseUse.hpp"
#include "Sequence.hpp"
#include "Timer.hpp"

CReverseUse::CReverseUse(const unsigned sequenceLength, vector<CSequence*>* permutations)
                        : IAlgorithm(sequenceLength, permutations) {}

unsigned CReverseUse::findPermutations(const bool showRunning) {
    if (m_sequenceLength == 0) {
        return 0;
    }

    CTimer tmr;
    tmr.start();
    
    CSequence baseSequence(m_sequenceLength);
    baseSequence.fillAscending();
    
    antylex(m_sequenceLength, baseSequence, tmr, showRunning);

    tmr.pause();
    if (showRunning) {
        cout << endl;
    }

    cout << "Permutations were found in " << tmr.getTime() << " seconds.\n\n";
    
    return m_permutations->size();
}

void CReverseUse::antylex(const unsigned m, CSequence& sequence, CTimer& tmr,
                          const bool showRunning, const unsigned indent) {
    if (m == 0) {
        tmr.pause();
        if (showRunning) {
            cout << "  ";
            sequence.print();
            cout << endl;
        }
        tmr.unpause();

        CSequence* sequenceOnList = addSequence();
        *sequenceOnList = sequence;
    }
    else {
        tmr.pause();
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
        tmr.unpause();

        for (unsigned u = 0; u < m; ++u) {
            antylex((m - 1), sequence, tmr, showRunning, (indent + 4));
            
            if (u < (m - 1)) {
                sequence.reverse(m);
            }
        }
    }
}
