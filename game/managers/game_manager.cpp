#include "game_manager.hpp"

using namespace game::manager;

static GameManager& GameManager::getInstance()
{
    return _instance;
};
