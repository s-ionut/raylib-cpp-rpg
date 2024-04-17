#include "game_manager.hpp"

using namespace game::manager;

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
    updatePlayers();
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

    delete _instance;
};

void GameManager::updatePlayers()
{
    //gonna have to update either from a savefile
    //either from a database (maybe multiplayer :D)
};

bool GameManager::createPlayer(PlayerUID pid, entity::ClassType class_type)
{
    game::entity::Character* resource = new game::entity::Character(class_type);

    if (resource)
    {
        _players[pid] = resource;
        return true;
    }

    return false;
};

game::entity::Character* GameManager::getPlayer(PlayerUID pid)
{
    if (!checkPlayer(pid))
    {
        if (createPlayer(pid, entity::ClassType::WARRIOR))
        {
            std::cout << "Player created!\n";
            return std::any_cast<game::entity::Character*>(_players[pid]);
        }
        else
        {
            // could not create player :(
        }
    }

    return _players[pid];
};

bool GameManager::checkPlayer(PlayerUID pid)
{
    std::cout << "Checking for PID: " << pid << std::endl;
    if (_players.find(pid) != _players.end())
    {
        std::cout << "Player with PID: " << pid << " found." << std::endl;
        return true;
    }

    std::cout << "Player with PID: " << pid << " NOT found." << std::endl;
    return false;
};

bool GameManager::deletePlayer(PlayerUID pid)
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