#pragma once

namespace core
{
  namespace serialization
  {
    class Serializable
    {
    public:
      virtual void save(std::ofstream& out) const = 0;
      virtual void load(std::ifstream& in)        = 0;
    };
  }
}