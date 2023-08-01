#include "timer.hpp"

using namespace core::time;

Timer::Timer()
{
    _start_time = std::chrono::system_clock::now();
};

Timer::~Timer()
{

};

void Timer::Refresh()
{
    _start_time = std::chrono::system_clock::now();
}

bool Timer::HasTimePassedMS(double milliseconds)
{
    _end_time = std::chrono::system_clock::now();
    
    std::chrono::duration<double, std::milli> time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(_end_time - _start_time);

    std::cout << "Time passed: " << time_passed.count() << std::endl;

    if (time_passed.count() >= milliseconds)
    {
        return true;
    }

    return false;
}
