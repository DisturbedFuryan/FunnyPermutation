#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

//==================================================================================================
class CTimer {
public:
    CTimer();
    
    /* Various actions. */
    void start();
    void stop();
    void pause();
    void unpause();

    /* Returns time in seconds. */
    double getTime();
    
    bool isStarted() const;
    bool isPaused() const;
    
private:
    long int m_startClockTicks;
    long int m_pausedTicks;
    
    struct timespec m_ts;
    
    /* Flags. */
    bool m_started;
    bool m_paused;
    
    long int getClockTicks();
};
//==================================================================================================

inline bool CTimer::isStarted() const {
    return m_started;
}

inline bool CTimer::isPaused() const {
    return m_paused;
}

#endif
