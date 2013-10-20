#ifndef APP_H
#define APP_H

#include <vector>
#include "Algorithm.h"
#include "Sequence.h"
#include "SteinhausJohnsonTrotter.h"

using namespace std;

class CApp {
public:
    enum AlgorithmType { SteinhausJohnsonTrotter };
    
    CApp(const unsigned sequenceLength, const AlgorithmType algorithmToUse);
    ~CApp();

private:
    IAlgorithm* m_algorithm;
    
    vector<CSequence*> m_permutations;
};

#endif
