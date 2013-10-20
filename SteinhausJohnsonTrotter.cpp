#include "SteinhausJohnsonTrotter.h"

CSteinhausJohnsonTrotter::CSteinhausJohnsonTrotter(const unsigned sequenceLength, vector<CSequence*>* permutations)
        : IAlgorithm(sequenceLength, permutations) {
    /* Creating array to holding movement directions of elements. */
    m_elementsDirections = new IUtility::Direction[sequenceLength];
    for (unsigned u; u < m_sequenceLength; ++u) {
        m_elementsDirections[u] = IUtility::Left;  // All elements are going to the left side at startup.
    }
}

CSteinhausJohnsonTrotter::~CSteinhausJohnsonTrotter() {
    delete [] m_elementsDirections;
}

void CSteinhausJohnsonTrotter::findPermutations() {
    /* Creating base sequence. */
    CSequence* sequence = addSequence();
    sequence->fillAscending();  // Base sequence looks like 1 2 3 4 5...
    
    /* Holding previous sequence. Initially it's the base sequence. */
    CSequence* prevSequence = sequence;
}

unsigned& CSteinhausJohnsonTrotter::largestMobileElement(const CSequence& source) const {
    unsigned firstElement = 0, secondElement = 1, thirdElement = 2, lastElement = (m_sequenceLength - 1);
    
    /* Searching for local largest mobile within the range: (first element; last element) */
    unsigned* candidate = &source.element(secondElement);
    for (unsigned u = thirdElement; u < lastElement; ++u) {
        if (source.element(u) > *candidate) {
            candidate = &source.element(u);
        }
    }
    
    /* Maybe first or last element is better candidate? Let's check it! */
    if ((source.element(firstElement) > *candidate) && (m_elementsDirections[firstElement] == IUtility::Right)) {
        candidate = &source.element(firstElement);
    }
    if ((source.element(lastElement) > *candidate) && (m_elementsDirections[lastElement] == IUtility::Left)) {
        candidate = &source.element(lastElement);
    }
    
    /* OK, we've got it. */
    return *candidate;
}
