#include "Utility.h"

void IUtility::printAdditionalZeros(const unsigned number, const unsigned digitsNumber) {
    for (unsigned u = 1, multiple = 10; u < digitsNumber; ++u, multiple *= 10) {
        if (number < multiple) {
            cout << "0";
        }
    }
}
