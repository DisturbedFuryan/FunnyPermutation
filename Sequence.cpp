#include "Sequence.h"

CSequence::CSequence(const unsigned length) : m_length(length) {
    m_array = new unsigned[length];
}

CSequence::~CSequence() {
    delete [] m_array;
}

bool CSequence::copyFrom(const CSequence& source) {
    if (m_length != source.m_length) {
        return false;
    }
    
    for (unsigned u = 0; u < m_length; ++u) {
        m_array[u] = source.m_array[u];
    }
    
    return true;
}

void CSequence::fillAscending() {
    IArray::fillAscending(m_array, m_length);
}

void CSequence::print() const {
    IArray::print(m_array, m_length);
}
