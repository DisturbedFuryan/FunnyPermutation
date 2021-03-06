#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

//==================================================================================================
class CSequence {
public:
    CSequence(const unsigned length);
    ~CSequence();
    
    CSequence& operator=(const CSequence& source);
    friend bool operator==(const CSequence& a, const CSequence& b);
    friend bool operator!=(const CSequence& a, const CSequence& b);
    
    void fillAscending();
    
    void reverse(const unsigned range);
    
    /* Get methods. */
    unsigned& element(const unsigned position) const;
    
    void print() const;
    
private:
    const unsigned m_length;

    unsigned* m_array;
};
//==================================================================================================

inline unsigned& CSequence::element(const unsigned position) const {
    return m_array[position];
}

#endif
