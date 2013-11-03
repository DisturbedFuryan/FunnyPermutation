#include "Timer.hpp"

CTimer::CTimer() : m_startClockTicks(0), m_pausedTicks(0), m_started(false), m_paused(false) {}

void CTimer::start() {
    m_started = true;
    m_paused = false;
    
    m_startClockTicks = getClockTicks();
}

void CTimer::stop() {
    m_started = false;
    m_paused = false;
}

void CTimer::pause() {
    if (m_started && !m_paused) {
        m_paused = true;
        
        m_pausedTicks = (getClockTicks() - m_startClockTicks);
    }
}

void CTimer::unpause() {
    if (m_paused) {
        m_paused = false;
        
        m_startClockTicks = (getClockTicks() - m_pausedTicks);
        
        m_pausedTicks = 0;
    }
}

double CTimer::getTime() {
    if (m_started) {
        if (m_paused) {
            return (static_cast<double>(m_pausedTicks) / 1000000000.0);
        }
        return (static_cast<double>(getClockTicks() - m_startClockTicks) / 1000000000.0);
    }
    return 0.0;
}

long int CTimer::getClockTicks(void) {
    clock_gettime(CLOCK_MONOTONIC, &m_ts);
    return ((m_ts.tv_sec * 1000000000) + m_ts.tv_nsec);
}
