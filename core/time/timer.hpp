#pragma once

// system specific
#include "etc/system_includes.h"
#include <iostream>

namespace core {
    namespace time {
        class Timer 
        {
            public:
                Timer();
                ~Timer();
                bool HasTimePassedMS(double milliseconds);
                void Refresh();
            
            private:
                std::chrono::time_point<std::chrono::system_clock> _start_time;
                std::chrono::time_point<std::chrono::system_clock> _end_time;
        };

    } // namespace time
} // namespace core