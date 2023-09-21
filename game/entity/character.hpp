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

        class Character : public Entity
        {
            public:
                Character();
                ~Character() {};
        };
    } // namespace entity
} // namespace game