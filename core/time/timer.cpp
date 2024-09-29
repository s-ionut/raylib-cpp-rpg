#include "timer.hpp"

using namespace core::time;

Timer::Timer() { m_startTime = std::chrono::system_clock::now(); };

Timer::~Timer() {

};

void Timer::refresh() { m_startTime = std::chrono::system_clock::now(); }

bool Timer::hasTimePassedMS(double milliseconds)
{
  m_endTime = std::chrono::system_clock::now();

  std::chrono::duration<double, std::milli> timePassed
    = std::chrono::duration_cast<std::chrono::milliseconds>(m_endTime
                                                            - m_startTime);

  if(timePassed.count() >= milliseconds)
  {
    return true;
  }

  return false;
}
