#ifndef UTILITY_HPP
#define UTILITY_HPP

//==================================================================================================
class IUtility {
public:
    enum Direction { Left, Right };
    
    static void swap(unsigned& a, unsigned& b);
    static void swap(Direction& a, Direction& b);
    
    static void printAdditionalZeros(const unsigned number, const unsigned digitsNumber);
    
    static unsigned getUnsigned(const char* statement);
    static unsigned short getUnsignedShort(const char* statement);
};
//==================================================================================================

inline void IUtility::swap(unsigned& a, unsigned& b) {
    const unsigned temp = a;
    a = b;
    b = temp;
}

inline void IUtility::swap(Direction& a, Direction& b) {
    const Direction temp = a;
    a = b;
    b = temp;
}

#endif
