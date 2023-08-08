#pragma once

// system specific
#include "core/etc/system_includes.h"

// game specific
#include "game/entity/character.hpp"

namespace game {
    namespace manager {
        using PlayerUID = unsigned int;

        class GameManager {
            private:
                ///TODO: map a UID to a Character object
                std::map<PlayerUID, entity::Character> players;
                GameManager() {}

                GameManager(const GameManager&) = delete;
                GameManager& operator=(const GameManager&) = delete;

            public:
                static GameManager& GameManager::getInstance()
                {
                    static GameManager instance;
                    return instance;
                };
        };
    } // namespace manager
} // namespace game