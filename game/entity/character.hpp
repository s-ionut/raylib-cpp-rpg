#pragma once

// game specific
#include "entity.hpp"

namespace game
{
  namespace entity
  {

    enum class ClassType
    {
      WARRIOR = 0,
      ASSASSIN,
      SURA,
      MAGE,
      COUNT
    };
    ClassType   getClassTypeByIndex(int index);
    std::string getClassNameByType(ClassType type);

    class Character : public Entity
    {
    public:
      Character() = delete;
      Character(ClassType classType);
      ~Character() {};

      void setClass(ClassType classType);
      void calcExp(int givenExp);
      void levelUp();

    private:
      void initChar();
      void setStats(int attack,
                    int defense,
                    int maxHp,
                    int maxMana,
                    int level,
                    int maxExp);

      ClassType m_class = ClassType::WARRIOR;
    };
  } // namespace entity
} // namespace game