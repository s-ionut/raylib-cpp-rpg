#pragma once

// system specific
#include "etc/system_includes.h"

namespace core {
    namespace manager {
        class GameManager {
            private:
                ///TODO: map a UID to a Character object
                std::map<int, std::string> players;
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
} // namespace core