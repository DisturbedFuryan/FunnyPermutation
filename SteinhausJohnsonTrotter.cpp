#include <iostream>
#include "Sequence.hpp"
#include "SteinhausJohnsonTrotter.hpp"
#include "Timer.hpp"

CSteinhausJohnsonTrotter::CSteinhausJohnsonTrotter(const unsigned sequenceLength,
                                                   vector<CSequence*>* permutations)
                                                  : IAlgorithm(sequenceLength, permutations) {
    /* Creating array to holding movement directions of elements. */
    m_elementsDirections = new IUtility::Direction[sequenceLength];
    for (unsigned u = 0; u < m_sequenceLength; ++u) {
        // All elements are going to the left side at startup.
        m_elementsDirections[u] = IUtility::Left;
    }
}

CSteinhausJohnsonTrotter::~CSteinhausJohnsonTrotter() {
    delete [] m_elementsDirections;
}

unsigned CSteinhausJohnsonTrotter::findPermutations(const bool showRunning) {
    /* Protection against officious users... */
    if (m_sequenceLength == 0) {
        return 0;
    }

    CTimer tmr;
    tmr.start();
    
    /* Creating the base sequence. Initially it's also a previous sequence. */
    CSequence* sequence = addSequence(), * prevSequence = sequence;
    sequence->fillAscending();
    
    unsigned largestMobileElementPosition, sequencesNumber = 1;
    
    /* Let's find the permutations! */
    while (localizeMobilesPositions(*sequence)) {  // No mobiles ends search for new permutations.
        tmr.pause();
        if (showRunning) {
            printState(sequencesNumber, *sequence);
        }
        tmr.unpause();
    
        // We've found mobiles! We can add a new sequence.
        sequence = addSequence();
        *sequence = *prevSequence;
        ++sequencesNumber;
        
        // Determining which of found is the largest.
        largestMobileElementPosition = localizeLargestMobilePosition(*sequence);
        
        // The largest mobile is going to the left or right direction?
        switch (m_elementsDirections[largestMobileElementPosition]) {
            case IUtility::Left:
                // Swapping the largest mobile with the left neighbor.
                IUtility::swap(sequence->element(largestMobileElementPosition),
                               sequence->element(largestMobileElementPosition - 1));
                IUtility::swap(m_elementsDirections[largestMobileElementPosition],
                               m_elementsDirections[largestMobileElementPosition - 1]);
                --largestMobileElementPosition;
                
                break;
                
            case IUtility::Right:
                // Swapping the largest mobile with the right neighbor.
                IUtility::swap(sequence->element(largestMobileElementPosition),
                               sequence->element(largestMobileElementPosition + 1));
                IUtility::swap(m_elementsDirections[largestMobileElementPosition],
                               m_elementsDirections[largestMobileElementPosition + 1]);
                ++largestMobileElementPosition;
                
                break;
        }
        
        // Looking for larger elements than the current.
        for (unsigned u = 0; u < m_sequenceLength; ++u) {
            if ((u != largestMobileElementPosition)
                && (sequence->element(u) > sequence->element(largestMobileElementPosition))) {
                // OK, we've got one! Let's change its direction.
                m_elementsDirections[u] = ((m_elementsDirections[u] == IUtility::Left)
                                           ? IUtility::Right : IUtility::Left);
            }
        }
        
        // Remember the new permutation.
        prevSequence = sequence;
    }
    
    tmr.pause();
    if (showRunning) {
        printState(sequencesNumber, *sequence); cout << endl;
    }

    cout << "Permutations were found in " << tmr.getTime() << " seconds.\n\n";
    
    return sequencesNumber;
}

bool CSteinhausJohnsonTrotter::localizeMobilesPositions(const CSequence& source) {
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
                        // Smaller element on path of the test element exist!
                        m_mobilesPositions.push_back(u);
                        // One smaller element is enough to decide that the test element is mobile.
                        break;
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

unsigned CSteinhausJohnsonTrotter::localizeLargestMobilePosition(const CSequence& source) const {
    unsigned largestElementPosition;

    {
        vector<unsigned>::const_iterator it = m_mobilesPositions.begin();
        largestElementPosition = *it;
        ++it;
        for ( ; it != m_mobilesPositions.end(); ++it) {
            if (source.element(*it) > source.element(largestElementPosition)) {
                largestElementPosition = *it;
            }
        }
    }

    return largestElementPosition;
}

void CSteinhausJohnsonTrotter::printState(const unsigned sequencesNumber,
                                          const CSequence& sequence) const {
    // Printing the number of sequences.
    IUtility::printAdditionalZeros(sequencesNumber, 5);
    cout << sequencesNumber << ":  ";
    
    // Printing the sequence elements with directions.
    for (unsigned u = 0; u < m_sequenceLength; ++u) {
        switch (m_elementsDirections[u]) {
            case IUtility::Left:
                cout << "<" << sequence.element(u) << " ";
                break;
                
            case IUtility::Right:
                cout << sequence.element(u) << "> ";
                break;
        }
    }
    
    // Printing mobile elements.
    cout << "   Mobile elements:  ";

    {
        vector<unsigned>::const_iterator it;
        for (it = m_mobilesPositions.begin(); it != m_mobilesPositions.end(); ++it) {
            cout << sequence.element(*it) << " ";
        }
    }
    
    cout << endl;
}
