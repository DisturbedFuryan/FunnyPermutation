#ifndef REVERSEUSE_HPP
#define REVERSEUSE_HPP

class CSequence;

#include <vector>
#include "Algorithm.hpp"

using namespace std;

//==================================================================================================
class CReverseUse : public IAlgorithm {
public:
    CReverseUse(const unsigned sequenceLength, vector<CSequence*>* permutations);

    unsigned findPermutations(const bool showRunning);
    
private:
    void antylex(const unsigned m, CSequence& sequence);
};
//==================================================================================================

#endif
