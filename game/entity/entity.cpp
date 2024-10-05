#include "entity.hpp"

using namespace game::entity;

Entity::Entity()
{
  m_level   = 1;
  m_currExp = 0;
  m_maxHp   = 100;
  m_maxMana = 50;
};