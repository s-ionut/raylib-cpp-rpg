#include "game_manager.hpp"

using namespace game::manager;

GameManager::GameManager()
{
    UpdatePlayers();
};

GameManager* GameManager::getInstance()
{
    return _instance;
};

GameManager::~GameManager()
{
    for (auto& pair : _players)
    {
        delete pair.second;
    }
    _players.clear();
};

void GameManager::UpdatePlayers()
{
    //gonna have to update either from a savefile
    //either from a database (maybe multiplayer :D)
};

game::entity::Character* GameManager::GetPlayer(PlayerUID pid)
{
    if (_players.find(pid) != _players.end())
    {
        return std::any_cast<game::entity::Character*>(_players[pid]);
    }

    game::entity::Character* resource = new game::entity::Character();

    if (resource)
    {
        _players[pid] = resource;
    }

    return resource;
};

bool GameManager::DeletePlayer(PlayerUID pid)
{
    auto it = _players.find(pid);
    if (it != _players.end())
    {
        delete _players[pid];
        _players.erase(it);
        return true;
    }

    return false;
};