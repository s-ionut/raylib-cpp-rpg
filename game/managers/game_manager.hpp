#pragma once

// game specific
#include "game/entity/character.hpp"

namespace game
{
  namespace manager
  {
    using PlayerUID = unsigned int;

    class GameManager
    {
    private:
      static GameManager* m_instance;

      /// TODO: map a UID to a Character object
      std::map<PlayerUID, entity::Character*> m_players;
      GameManager();
      ~GameManager();

      GameManager(const GameManager&)            = delete;
      GameManager& operator=(const GameManager&) = delete;

    public:
      static GameManager* getInstance();
      entity::Character*  getPlayer(PlayerUID pid);
      bool createPlayer(PlayerUID pid, entity::ClassType class_type);
      bool checkPlayer(PlayerUID pid);
      bool deletePlayer(PlayerUID pid);
      void updatePlayers();
    };
  } // namespace manager
} // namespace game