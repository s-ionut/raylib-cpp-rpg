#pragma once

namespace core
{
  namespace time
  {
    class Timer
    {
    public:
      Timer();
      ~Timer();
      bool hasTimePassedMS(double milliseconds);
      void refresh();

    private:
      std::chrono::time_point<std::chrono::system_clock> _start_time;
      std::chrono::time_point<std::chrono::system_clock> _end_time;
    };

  } // namespace time
} // namespace core