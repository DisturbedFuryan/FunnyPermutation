#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

class CSequence;

#include <vector>
#include "Singleton.hpp"

using namespace std;

//==================================================================================================
class IAlgorithm : public ISingleton<IAlgorithm> {
public:
    IAlgorithm(const unsigned sequenceLength, vector<CSequence*>* permutations);
    
    virtual unsigned findPermutations(const bool showRunning = false) = 0;
    
protected:
    const unsigned m_sequenceLength;
    
    vector<CSequence*>* m_permutations;
    
    CSequence* addSequence();
};
//==================================================================================================

#endif
