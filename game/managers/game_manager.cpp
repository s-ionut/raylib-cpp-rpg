#include "game_manager.hpp"

using namespace game::manager;

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
    UpdatePlayers();
};

GameManager* GameManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new GameManager();
    }
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
    if (CheckPlayer(pid))
    {
        return std::any_cast<game::entity::Character*>(_players[pid]);
    }
    
    // game::entity::Character* resource = new game::entity::Character();

    // if (resource)
    // {
    //     _players[pid] = resource;
    // }

    return nullptr;
};

bool GameManager::SetPlayer(PlayerUID pid, entity::ClassType class_type)
{
    if (CheckPlayer(pid))
    {
        return false;
    }
    
    game::entity::Character* resource = new game::entity::Character(class_type);

    if (resource)
    {
        _players[pid] = resource;
    }
};

bool GameManager::CheckPlayer(PlayerUID pid)
{
    if (_players.find(pid) != _players.end())
    {
        return true;
    }

    return false;
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