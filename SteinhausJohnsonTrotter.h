#ifndef STEINHAUSJOHNSONTROTTER_H
#define STEINHAUSJOHNSONTROTTER_H

#include <vector>
#include "Algorithm.h"
#include "Sequence.h"
#include "Utility.h"

using namespace std;

class CSteinhausJohnsonTrotter : public IAlgorithm {
public:
    CSteinhausJohnsonTrotter(const unsigned sequenceLength, vector<CSequence*>* permutations);
    ~CSteinhausJohnsonTrotter();

    unsigned findPermutations(const bool showRunning);
    
private:
    IUtility::Direction* m_elementsDirections;
    
    vector<unsigned> m_mobilesPositions;
    
    bool localizeMobilesPositions(const CSequence& source);
    
    unsigned localizeLargestElementPositionWithinMobiles(const CSequence& source) const;
    
    void printState(const unsigned sequencesNumber, const CSequence& sequence) const;
};

#endif
