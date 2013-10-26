#ifndef STEINHAUSJOHNSONTROTTER_HPP
#define STEINHAUSJOHNSONTROTTER_HPP

class CSequence;

#include <vector>
#include "Algorithm.hpp"
#include "Utility.hpp"

using namespace std;

//==================================================================================================
class CSteinhausJohnsonTrotter : public IAlgorithm {
public:
    CSteinhausJohnsonTrotter(const unsigned sequenceLength, vector<CSequence*>* permutations);
    ~CSteinhausJohnsonTrotter();

    unsigned findPermutations(const bool showRunning);
    
private:
    IUtility::Direction* m_elementsDirections;
    
    vector<unsigned> m_mobilesPositions;
    
    bool localizeMobilesPositions(const CSequence& source);
    
    unsigned localizeLargestMobilePosition(const CSequence& source) const;
    
    void printState(const unsigned sequencesNumber, const CSequence& sequence) const;
};
//==================================================================================================

#endif
