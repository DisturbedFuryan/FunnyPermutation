#include "Sequence.h"

CSequence::CSequence(const unsigned length) : m_length(length) {
    m_array = new unsigned[length];
}

CSequence::~CSequence() {
    delete [] m_array;
}

void CSequence::fillAscending() {
    IArray::fillAscending(m_array, m_length);
}

void CSequence::print() const {
    IArray::print(m_array, m_length);
}
