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
                
                void SetClass(ClassType class);

            private:
                void InitChar();

                ClassType _class;
        };
    } // namespace entity
} // namespace game