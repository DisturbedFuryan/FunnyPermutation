#include "Algorithm.hpp"
#include "Sequence.hpp"

IAlgorithm::IAlgorithm(const unsigned sequenceLength, vector<CSequence*>* permutations)
                      : m_sequenceLength(sequenceLength), m_permutations(permutations) {}

CSequence* IAlgorithm::addSequence() {
    CSequence* sequence = new CSequence(m_sequenceLength);
    m_permutations->push_back(sequence);
    return sequence;
}
