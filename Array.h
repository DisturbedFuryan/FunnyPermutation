#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class IArray {
public:
    static void fillAscending(unsigned* array, const unsigned length);
    
    static void copy(const unsigned* source, unsigned* destination, const unsigned length);
    
    static bool areIdentical(const unsigned* arrA, const unsigned* arrB, const unsigned length);
    
    static void print(const unsigned* array, const unsigned length);
};

#endif
