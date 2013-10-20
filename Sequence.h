#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Array.h"

class CSequence {
public:
    CSequence(const unsigned length);
    ~CSequence();
    
    void fillAscending();
    
    unsigned& element(const unsigned position) const { return m_array[position]; }
    
    void print() const;
    
private:
    const unsigned m_length;

    unsigned* m_array;
};

#endif
