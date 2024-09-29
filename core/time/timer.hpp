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
      std::chrono::time_point<std::chrono::system_clock> m_startTime;
      std::chrono::time_point<std::chrono::system_clock> m_endTime;
    };

  } // namespace time
} // namespace core