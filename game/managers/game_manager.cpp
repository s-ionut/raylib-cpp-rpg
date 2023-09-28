#include "game_manager.hpp"

using namespace game::manager;

static GameManager& GameManager::getInstance()
{
    return _instance;
};

entity::Character* GameManager::GetPlayer(PlayerUID pid)
{
    if (_players.find(pid) != _players.end())
    {
        return _players[pid];
    }

    entity::Character* resource = nullptr;

    resource = new entity::Character();

    if (resource)
    {
        _players[pid] = resource;
    }

    return resource;
};