#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include "App.hpp"
#include "Singleton.hpp"

//==================================================================================================
class CParameters : public ISingleton<CParameters> {
public:
    CParameters();

    void getParametersFromUser();

    /* Get methods. */
    unsigned sequenceLength() const;
    CApp::AlgorithmType algorithmType() const;
    bool printWorkingAlgorithm() const;
    bool printPermutations() const;
private:
    /* Parameters. */
    unsigned m_sequenceLength;
    CApp::AlgorithmType m_algorithmType;
    bool m_printWorkingAlgorithm;
    bool m_printPermutations;

    unsigned getSequenceLengthFromUser() const;
    CApp::AlgorithmType getAlgorithmTypeFromUser() const;
    bool getPermissionForPrintWorkingAlgorithm() const;
    bool getPermissionForPrintPermutations() const;
};
//==================================================================================================

inline unsigned CParameters::sequenceLength() const {
    return m_sequenceLength;
}

inline CApp::AlgorithmType CParameters::algorithmType() const {
    return m_algorithmType;
}

inline bool CParameters::printWorkingAlgorithm() const {
    return m_printWorkingAlgorithm;
}

inline bool CParameters::printPermutations() const {
    return m_printPermutations;
}

#endif
