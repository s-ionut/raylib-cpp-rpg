#pragma once

// game specific
#include "entity.hpp"

namespace game {
    namespace entity {
        class Character : public Entity
        {
            public:
                Character();
                ~Character() {};
        };
    } // namespace entity
} // namespace game