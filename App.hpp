#ifndef APP_HPP
#define APP_HPP

class CSequence;
class IAlgorithm;

#include <vector>
#include "Singleton.hpp"

using namespace std;

//==================================================================================================
class CApp : public ISingleton<CApp> {
public:
    enum AlgorithmType { SteinhausJohnsonTrotter, ReverseUse, Bmu };
    
    CApp(const unsigned sequenceLength, const AlgorithmType algorithmToUse);
    ~CApp();
    
    /* Finds the permutations and returns a number of found. */
    unsigned findPermutations(const bool showRunning = false);
    
    void printPermutations() const;
    
    bool validation() const;

    /* Get methods. */
    const vector<CSequence*>& permutations() const;

private:
    IAlgorithm* m_algorithm;
    
    vector<CSequence*> m_permutations;
};
//==================================================================================================

inline const vector<CSequence*>& CApp::permutations() const {
    return m_permutations;
}

#endif
