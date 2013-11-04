#ifndef BMU_HPP
#define BMU_HPP

class CSequence;
class CTimer;

#include <vector>
#include "Algorithm.hpp"

using namespace std;

//==================================================================================================
class CBmu : public IAlgorithm {
public:
    CBmu(const unsigned sequenceLength, vector<CSequence*>* permutations,
         const bool recursiveSearch = false);

    unsigned findPermutations(const bool showRunning);

private:
    const bool m_recursiveSearch;

    void recursivePerm(const unsigned m, CSequence& sequence, CTimer& tmr,
                       const bool showRunning = false, const unsigned indent = 0);

    void nonrecursivePerm(CSequence& baseSequence, CTimer& tmr, const bool showRunning = false);

    unsigned b(const unsigned m, const unsigned u) const;
};
//==================================================================================================

#endif
