#include <iomanip>
#include <iostream>
#include "Bmu.hpp"
#include "Sequence.hpp"
#include "Utility.hpp"

CBmu::CBmu(const unsigned sequenceLength, vector<CSequence*>* permutations,
           const bool recursiveSearch)
          : IAlgorithm(sequenceLength, permutations), m_recursiveSearch(recursiveSearch) {}

unsigned CBmu::findPermutations(const bool showRunning) {
    if (m_sequenceLength == 0) {
        return 0;
    }
    
    CSequence baseSequence(m_sequenceLength);
    baseSequence.fillAscending();
    
    if (m_recursiveSearch) {
        recursivePerm(m_sequenceLength, baseSequence, showRunning);
    }
    else {
        nonrecursivePerm(baseSequence, showRunning);
    }

    if (showRunning) {
        cout << endl;
    }

    return m_permutations->size();
}

void CBmu::recursivePerm(const unsigned m, CSequence& sequence,
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

            cout << "PERM(" << m << ")";
            
            if (m > 1) {
                cout << endl;
            }
        }

        for (unsigned u = 0; u < m; ++u) {
            recursivePerm((m - 1), sequence, showRunning, (indent + 4));
            
            if (u < (m - 1)) {
                IUtility::swap(sequence.element(b(m, u)), sequence.element(m - 1));
            }
        }
    }
}

void CBmu::nonrecursivePerm(const CSequence& baseSequence, const bool showRunning) {
    cout << "TO WRITE\n";
}

unsigned CBmu::b(const unsigned m, const unsigned u) const {
    if (((m % 2) == 0) && (m > 2)) {
        if (u < (m - 2)) {
            return u;
        }
        else {
            return (m - 3);
        }
    }
    else {
        return (m - 2);
    }
}
