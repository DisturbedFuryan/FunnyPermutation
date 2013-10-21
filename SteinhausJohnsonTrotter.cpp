#include "SteinhausJohnsonTrotter.h"

CSteinhausJohnsonTrotter::CSteinhausJohnsonTrotter(const unsigned sequenceLength, vector<CSequence*>* permutations)
        : IAlgorithm(sequenceLength, permutations) {
    /* Creating array to holding movement directions of elements. */
    m_elementsDirections = new IUtility::Direction[sequenceLength];
    for (unsigned u = 0; u < m_sequenceLength; ++u) {
        m_elementsDirections[u] = IUtility::Left;  // All elements are going to the left side at startup.
    }
}

CSteinhausJohnsonTrotter::~CSteinhausJohnsonTrotter() {
    delete [] m_elementsDirections;
}

void CSteinhausJohnsonTrotter::findPermutations() {
    /* Creating the base sequence. Initially it's also a previous sequence. */
    CSequence* sequence = addSequence(), * prevSequence = sequence;
    sequence->fillAscending();
    
    /* Let's find the permutations! */
    while (localizeMobilesPositions(*sequence)) {  // No mobiles ends search for new permutations.
        // We've found mobiles! We can add a new sequence.
        sequence = addSequence();
        sequence->copyFrom(*prevSequence);
        
        unsigned largestMobileElementPosition;
        
        // Determining which of found is the largest.
        largestMobileElementPosition = localizeLargestElementPositionWithinMobiles(*sequence);
        
        // The largest mobile is going to the left or right direction?
        switch (m_elementsDirections[largestMobileElementPosition]) {
            case IUtility::Left:
                // Swapping the largest mobile with the left neighbour.
                IUtility::swap(sequence->element(largestMobileElementPosition), sequence->element(largestMobileElementPosition - 1));
                IUtility::swap(m_elementsDirections[largestMobileElementPosition], m_elementsDirections[largestMobileElementPosition - 1]);
                --largestMobileElementPosition;
                
                break;
                
            case IUtility::Right:
                // Swapping the largest mobile with the right neighbour.
                IUtility::swap(sequence->element(largestMobileElementPosition), sequence->element(largestMobileElementPosition + 1));
                IUtility::swap(m_elementsDirections[largestMobileElementPosition], m_elementsDirections[largestMobileElementPosition + 1]);
                ++largestMobileElementPosition;
                
                break;
        }
        
        // Looking for larger elements than the current.
        for (unsigned u = 0; u < m_sequenceLength; ++u) {
            if ((u != largestMobileElementPosition) && (sequence->element(u) > sequence->element(largestMobileElementPosition))) {
                // OK, we've got one! Let's change its direction.
                m_elementsDirections[u] = ((m_elementsDirections[u] == IUtility::Left) ? IUtility::Right : IUtility::Left);
            }
        }
        
        // Remember the new permutation.
        prevSequence = sequence;
    }
    
    /*do {
        CSequence* sequence = addSequence();
        sequence->copyFrom(*prevSequence);
        
        // TEMP
        for (unsigned u = 0; u < m_sequenceLength; ++u) {
            switch (m_elementsDirections[u]) {
                case IUtility::Left:
                    cout << "<" << sequence->element(u) << " ";
                    break;
                    
                case IUtility::Right:
                    cout << sequence->element(u) << "> ";
                    break;
            }
        }
        cout << endl;
        cout << "Mobiles elements: ";
        vector<unsigned>::iterator it = m_mobilesPositions.begin();
        for ( ; it != m_mobilesPositions.end(); ++it) {
            cout << sequence->element(*it) << " ";
        }
        cout << endl;
        
        unsigned largestMobileElementPosition = localizeLargestElementPositionWithinMobiles(*sequence);
        
        switch (m_elementsDirections[largestMobileElementPosition]) {
            case IUtility::Left:
                IUtility::swap(sequence->element(largestMobileElementPosition), sequence->element(largestMobileElementPosition - 1));
                IUtility::swap(m_elementsDirections[largestMobileElementPosition], m_elementsDirections[largestMobileElementPosition - 1]);
                break;
                
            case IUtility::Right:
                IUtility::swap(sequence->element(largestMobileElementPosition), sequence->element(largestMobileElementPosition + 1));
                IUtility::swap(m_elementsDirections[largestMobileElementPosition], m_elementsDirections[largestMobileElementPosition + 1]);
                break;
        }
        
        prevSequence = sequence;
    } while(localizeMobilesPositions(*sequence));*/
    
    /*CSequence* sequence = addSequence();
    sequence->element(0) = 3;
    sequence->element(1) = 2;
    sequence->element(2) = 5;
    sequence->print(); cout << endl;
    if (localizeMobilesPositions(*sequence)) {
        cout << "Mobile elements exist!\n";
    }
    else {
        cout << "Mobile elements don't exist!\n";
    }*/
}

const bool CSteinhausJohnsonTrotter::localizeMobilesPositions(const CSequence& source) {
    /* Removing previously localized mobiles. */
    m_mobilesPositions.clear();
    
    /* Let's see if there are any mobiles! */
    for (unsigned u = 0; u < m_sequenceLength; ++u) {
        // Checking element with u index.
        switch (m_elementsDirections[u]) {  // Determining which direction the test element goes.
            case IUtility::Left:
                // Searching for any smaller element on the test element path.
                for (unsigned v = u; v > 0; --v) {
                    if (source.element(v - 1) < source.element(u)) {
                        m_mobilesPositions.push_back(u);  // Smaller element on path of the test element exist!
                        break;  // One smaller element is enough to decide that the test element is mobile.
                    }
                }
                break;
                
            case IUtility::Right:
                // Analogous behavior to the left direction.
                for (unsigned v = (u + 1); v < m_sequenceLength; ++v) {
                    if (source.element(v) < source.element(u)) {
                        m_mobilesPositions.push_back(u);
                        break;
                    }
                }
                break;
        }
    }
    
    /* Returning true if there are any mobiles. */
    return !m_mobilesPositions.empty();
}

const unsigned CSteinhausJohnsonTrotter::localizeLargestElementPositionWithinMobiles(const CSequence& source) const {
    vector<unsigned>::const_iterator it = m_mobilesPositions.begin();
    unsigned largestElementPosition = *it;
    ++it;
    for ( ; it != m_mobilesPositions.end(); ++it) {
        if (source.element(*it) > source.element(largestElementPosition)) {
            largestElementPosition = *it;
        }
    }
    return largestElementPosition;
}
