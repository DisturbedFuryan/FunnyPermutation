#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include "Sequence.h"

using namespace std;

class IAlgorithm {
public:
    IAlgorithm(const unsigned sequenceLength, vector<CSequence*>* permutations);
    
    virtual void findPermutations() = 0;
    
protected:
    const unsigned m_sequenceLength;
    
    vector<CSequence*>* m_permutations;
};

#endif
