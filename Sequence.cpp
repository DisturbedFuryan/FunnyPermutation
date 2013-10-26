#include "Array.hpp"
#include "Sequence.hpp"

CSequence::CSequence(const unsigned length) : m_length(length) {
    m_array = new unsigned[length];
}

CSequence::~CSequence() {
    delete [] m_array;
}

CSequence& CSequence::operator=(const CSequence& source) {
    if (m_length == source.m_length) {
        for (unsigned u = 0; u < m_length; ++u) {
            m_array[u] = source.m_array[u];
        }
    }
    return *this;
}

bool operator==(const CSequence& a, const CSequence& b) {
    if (a.m_length != b.m_length) {
        return false;
    }
    return IArray::areIdentical(a.m_array, b.m_array, a.m_length);
}

bool operator!=(const CSequence& a, const CSequence& b) {
    if (a.m_length != b.m_length) {
        return true;
    }
    return !IArray::areIdentical(a.m_array, b.m_array, a.m_length);
}

void CSequence::fillAscending() {
    IArray::fillAscending(m_array, m_length);
}

void CSequence::reverse(const unsigned range) {
    if ((range > 1) && (range <= m_length)) {
        IArray::reverse(m_array, range);
    }
}

void CSequence::print() const {
    IArray::print(m_array, m_length);
}
