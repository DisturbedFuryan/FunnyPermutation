#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include "Sequence.h"

using namespace std;

class IAlgorithm {
public:
    IAlgorithm(const unsigned sequenceLength, vector<CSequence*>* permutations);
    
    virtual const unsigned findPermutations(const bool showRunning = false) = 0;
    
protected:
    const unsigned m_sequenceLength;
    
    vector<CSequence*>* m_permutations;
    
    CSequence* addSequence() { CSequence* sequence = new CSequence(m_sequenceLength); m_permutations->push_back(sequence); return sequence; }
};

#endif
