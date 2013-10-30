#include <iomanip>
#include <iostream>
#include "Array.hpp"
#include "Bmu.hpp"
#include "Sequence.hpp"
#include "Utility.hpp"

CBmu::CBmu(const unsigned sequenceLength, vector<CSequence*>* permutations,
           const bool recursiveSearch)
          : IAlgorithm(sequenceLength, permutations), m_recursiveSearch(recursiveSearch) {}

unsigned CBmu::findPermutations(const bool showRunning) {
    if (m_sequenceLength == 0) {
        return 0;
    }
    
    CSequence baseSequence(m_sequenceLength);
    baseSequence.fillAscending();
    
    if (m_recursiveSearch) {
        recursivePerm(m_sequenceLength, baseSequence, showRunning);
    }
    else {
        nonrecursivePerm(baseSequence, showRunning);
    }

    if (showRunning) {
        cout << endl;
    }

    return m_permutations->size();
}

void CBmu::recursivePerm(const unsigned m, CSequence& sequence,
                 const bool showRunning, const unsigned indent) {
    if (m == 0) {
        if (showRunning) {
            cout << "  ";
            sequence.print();
            cout << endl;
        }

        CSequence* sequenceOnList = addSequence();
        *sequenceOnList = sequence;
    }
    else {
        if (showRunning) {
            if (indent) {
                cout << setw(indent) << ' ';
                cout << "\\__";
            }

            cout << "PERM(" << m << ")";
            
            if (m > 1) {
                cout << endl;
            }
        }

        for (unsigned u = 0; u < m; ++u) {
            recursivePerm((m - 1), sequence, showRunning, (indent + 4));
            
            if (u < (m - 1)) {
                IUtility::swap(sequence.element(b(m, u)), sequence.element(m - 1));
            }
        }
    }
}

void CBmu::nonrecursivePerm(CSequence& baseSequence, const bool showRunning) {
    /* Putting the base sequence on list. */
    CSequence* sequenceOnList = addSequence();
    *sequenceOnList = baseSequence;

    if (m_sequenceLength > 1) {  // If any permutation is still to find.
        /* Holding previous sequence. */
        CSequence* prevSequence = &baseSequence;

        /* Making additional array which holds the amount of use the m.
         * mUseCount[1]: m = 1, mUseCount[2]: m = 2, mUseCount[3]: m = 3, ...
         * And yes, first cell is unused. */
        unsigned mUseCount[m_sequenceLength];

        //Initially it's filled with zeros of course.
        IArray::fillWithZeros(mUseCount, m_sequenceLength);

        /* Actualizing mUseCount until it will be filled with zeros only.
         * It's true that the array is filled with zeros right now,
         * but on the first loop it's going to change. */
        do {
            if (showRunning) {
                /* Just printing status of mUseCount array. */
                cout << "mUseCount: [ "; 
                IArray::print(mUseCount, m_sequenceLength);
                cout << "]\n";
            }

            /* Let's check values inside the mUseCount array.
             * All elements before "the first found free m" will be reset. */
            for (unsigned m = 1; m < m_sequenceLength; ++m) {
                if (mUseCount[m] < m) {  // We still have free space for reuse the m.
                    // Adding a new sequence with values from previous one.
                    CSequence* sequence = addSequence();
                    *sequence = *prevSequence;

                    // Making a new permutation.
                    IUtility::swap(sequence->element(b((m + 1), mUseCount[m])),
                                   sequence->element(m));

                    // The m was used, increasing the counter.
                    ++mUseCount[m];

                    prevSequence = sequence;  // Remember the permutation.
                    
                    // "The free m" was found, we don't look for the other one inside the same loop.
                    break;
                }
                else {
                    mUseCount[m] = 0;  // Reset the counter for the m.
                }
            }
        } while (!IArray::isFillWithZeros(mUseCount, m_sequenceLength));
    }
}

unsigned CBmu::b(const unsigned m, const unsigned u) const {
    if (((m % 2) == 0) && (m > 2)) {
        if (u < (m - 2)) {
            return u;
        }
        else {
            return (m - 3);
        }
    }
    else {
        return (m - 2);
    }
}
