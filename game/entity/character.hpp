#pragma once

// game specific
#include "entity.hpp"

namespace game {
    namespace entity {
        ClassType getClassTypeByIndex(int index);
        std::string getClassNameByType(ClassType type);

        class Character : public Entity
        {
            public:
                Character() = delete;
                Character(ClassType classType);
                ~Character() {};
                
                void setClass(ClassType classType);

            private:
                void initChar();
                void setStats(int attack, int defense, int max_hp, int max_mana, int str, int intl, int dex, int level, int max_exp);
        };
    } // namespace entity
} // namespace game