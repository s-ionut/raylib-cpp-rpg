#pragma once

// game specific
#include "entity.hpp"

namespace game {
    namespace entity {

        enum class ClassType
        {
            WARRIOR = 0,
            ASSASSIN,
            SURA,
            MAGE,
            COUNT
        };
        ClassType getClassTypeByIndex(int index);

        class Character : public Entity
        {
            public:
                Character(ClassType classType);
                ~Character() {};
                
                void setClass(ClassType classType);

            private:
                void initChar();
                void setStats(int attack, int defense, int max_hp, int max_mana, int str, int intl, int dex, int level, int max_exp);

                ClassType _class = ClassType::WARRIOR;
        };
    } // namespace entity
} // namespace game