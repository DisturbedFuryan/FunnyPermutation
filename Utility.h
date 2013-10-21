#ifndef UTILITY_H
#define UTILITY_H

class IUtility {
public:
    enum Direction { Left, Right };
    
    static void swap(unsigned& a, unsigned& b) { const unsigned temp = a; a = b; b = temp; }
    static void swap(Direction& a, Direction& b) { const Direction temp = a; a = b; b = temp; }
};

#endif
