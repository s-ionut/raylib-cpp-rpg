#include "entity.hpp"

using namespace game::entity;

Entity::Entity()
{
  m_level   = 1;
  m_currExp = 0;
  m_maxHp   = 100;
  m_maxMana = 50;
};

void Entity::Update() {

};

std::string Entity::getName() const { return m_name; };

int Entity::getAvatar() const { return m_avatar; };

int Entity::getMaxHP() const { return m_maxHp; };

int Entity::getMaxMana() const { return m_maxMana; };

int Entity::getAttack() const { return m_attack; };

int Entity::getDefense() const { return m_defense; };

int Entity::getLevel() const { return m_level; };

int Entity::getMaxExp() const { return m_maxExp; };

int Entity::getCurrExp() const { return m_currExp; };

void Entity::setName(const std::string name) { m_name = name; };

void Entity::setAvatar(const int avatar) { m_avatar = avatar; };

void Entity::setMaxHP(const int maxHp) { m_maxHp = maxHp; };

void Entity::setMaxMana(const int maxMana) { m_maxMana = maxMana; };

void Entity::setAttack(const int attack) { m_attack = attack; };

void Entity::setDefense(const int defense) { m_defense = defense; };

void Entity::setLevel(const int level) { m_level = level; };

void Entity::setMaxExp(const int maxExp) { m_maxExp = maxExp; };

void Entity::setCurrExp(const int currExp) { m_currExp = currExp; };