#include "Array.h"

void IArray::fillAscending(unsigned* array, const unsigned length) {
    for (unsigned u = 0; u < length; ++u) {
        array[u] = (u + 1);
    }
}

void IArray::copy(const unsigned* source, unsigned* destination, const unsigned length) {
    for (unsigned u = 0; u < length; ++u) {
        destination[u] = source[u];
    }
}

bool IArray::areIdentical(const unsigned* arrA, const unsigned* arrB, const unsigned length) {
    for (unsigned u = 0; u < length; ++u) {
        if (arrA[u] != arrB[u]) {
            return false;
        }
    }
    return true;
}

void IArray::print(const unsigned* array, const unsigned length) {
    for (unsigned u = 0; u < length; ++u) {
        cout << array[u] << " ";
    }
}
