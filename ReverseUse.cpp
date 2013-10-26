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
    
    antylex(m_sequenceLength, baseSequence);
    
    return m_permutations->size();
}

void CReverseUse::antylex(const unsigned m, CSequence& sequence) {
    if (m == 0) {
        CSequence* sequenceOnList = addSequence();
        *sequenceOnList = sequence;
    }
    else {
        for (unsigned u = 0; u < m; ++u) {
            antylex((m - 1), sequence);
            
            if (u < (m - 1)) {
                sequence.reverse(m);
            }
        }
    }
}
