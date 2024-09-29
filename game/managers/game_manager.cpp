#include "game_manager.hpp"

using namespace game::manager;

GameManager* GameManager::m_instance = nullptr;

GameManager::GameManager() { updatePlayers(); };

GameManager* GameManager::getInstance()
{
  if(m_instance == nullptr)
  {
    m_instance = new GameManager();
  }
  return m_instance;
};

GameManager::~GameManager()
{
  for(auto& pair : m_players)
  {
    delete pair.second;
  }
  m_players.clear();

  delete m_instance;
};

void GameManager::updatePlayers() {
  // gonna have to update either from a savefile
  // either from a database (maybe multiplayer :D)
};

bool GameManager::createPlayer(PlayerUID pid, entity::ClassType class_type)
{
  game::entity::Character* resource = new game::entity::Character(class_type);

  if(resource)
  {
    m_players[pid] = resource;
    return true;
  }

  return false;
};

game::entity::Character* GameManager::getPlayer(PlayerUID pid)
{
  if(!checkPlayer(pid))
  {
    if(createPlayer(pid, entity::ClassType::WARRIOR))
    {
      std::cout << "Player created!\n";
      return std::any_cast<game::entity::Character*>(m_players[pid]);
    }
    else
    {
      // could not create player :(
    }
  }

  return m_players[pid];
};

bool GameManager::checkPlayer(PlayerUID pid)
{
  std::cout << "Checking for PID: " << pid << std::endl;
  if(m_players.find(pid) != m_players.end())
  {
    std::cout << "Player with PID: " << pid << " found." << std::endl;
    return true;
  }

  std::cout << "Player with PID: " << pid << " NOT found." << std::endl;
  return false;
};

bool GameManager::deletePlayer(PlayerUID pid)
{
  auto it = m_players.find(pid);
  if(it != m_players.end())
  {
    delete m_players[pid];
    m_players.erase(it);
    return true;
  }

  return false;
};