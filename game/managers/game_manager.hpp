#pragma once

// system specific
#include "core/etc/system_includes.h"

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
      static GameManager* _instance;

      /// TODO: map a UID to a Character object
      std::map<PlayerUID, entity::Character*> _players;
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