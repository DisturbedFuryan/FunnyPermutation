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

    void findPermutations();
    
private:
    IUtility::Direction* m_elementsDirections;
    
    vector<unsigned> m_mobilesPositions;
    
    const bool localizeMobilesPositions(const CSequence& source);
    
    const unsigned localizeLargestElementPositionWithinMobiles(const CSequence& source) const;
};

#endif
