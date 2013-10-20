#ifndef STEINHAUSJOHNSONTROTTER_H
#define STEINHAUSJOHNSONTROTTER_H

#include <vector>
#include "Algorithm.h"
#include "Sequence.h"

using namespace std;

class CSteinhausJohnsonTrotter : public IAlgorithm {
public:
    CSteinhausJohnsonTrotter(const unsigned sequenceLength, vector<CSequence*>* permutations);

    void findPermutations();
};

#endif
