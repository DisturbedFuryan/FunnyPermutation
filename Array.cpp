#include <iostream>
#include "Array.hpp"
#include "Utility.hpp"

using namespace std;

void IArray::fillWithZeros(unsigned* array, const unsigned length) {
    for (unsigned u = 0; u < length; ++u) {
        array[u] = 0;
    }
}

bool IArray::isFillWithZeros(unsigned* array, const unsigned length) {
    for (unsigned u = 0; u < length; ++u) {
        if (array[u] != 0) {
            return false;
        }
    }
    return true;
}

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

void IArray::reverse(unsigned* array, const unsigned range) {
    for (unsigned u = 0, v = (range - 1); u < (range / 2); ++u, --v) {
        IUtility::swap(array[u], array[v]);
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
