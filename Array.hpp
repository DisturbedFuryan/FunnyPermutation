#ifndef ARRAY_HPP
#define ARRAY_HPP

//==================================================================================================
class IArray {
public:
    static void fillAscending(unsigned* array, const unsigned length);
    
    static void copy(const unsigned* source, unsigned* destination, const unsigned length);
    
    static void reverse(unsigned* array, const unsigned range);
    
    static bool areIdentical(const unsigned* arrA, const unsigned* arrB, const unsigned length);
    
    static void print(const unsigned* array, const unsigned length);
};
//==================================================================================================

#endif
