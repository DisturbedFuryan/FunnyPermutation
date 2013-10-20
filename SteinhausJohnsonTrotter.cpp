#include "SteinhausJohnsonTrotter.h"

CSteinhausJohnsonTrotter::CSteinhausJohnsonTrotter(const unsigned sequenceLength, vector<CSequence*>* permutations)
        : IAlgorithm(sequenceLength, permutations) {
}

void CSteinhausJohnsonTrotter::findPermutations() {
    /* TEST ONLY */
    CSequence* sequence = addSequence();
    sequence->element(0) = 9;
}
