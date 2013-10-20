#include "Algorithm.h"

IAlgorithm::IAlgorithm(const unsigned sequenceLength, vector<CSequence*>* permutations)
        : m_sequenceLength(sequenceLength), m_permutations(permutations) {
}
