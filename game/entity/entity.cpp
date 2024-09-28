#include "entity.hpp"

using namespace game::entity;

Entity::Entity()
{
  _level     = 1;
  _curr_exp  = 0;
  _curr_hp   = _max_hp;
  _curr_mana = _max_mana;
};

void Entity::Update() {

};

void Entity::levelUp()
{
  _level += 1;
  _curr_exp = 0;

  if(_curr_exp > _max_exp)
  {
    _curr_exp = (_curr_exp - _max_exp);
  }

  _max_exp = 10 * _level;
};

void Entity::calcExp(int given_exp)
{
  _curr_exp += given_exp;

  if(_curr_exp >= _max_exp)
  {
    levelUp();
  }
};

std::string Entity::getName() const { return _name; };

int Entity::getAvatar() const { return _avatar; };

int Entity::getMaxHP() const { return _max_hp; };

int Entity::getMaxMana() const { return _max_mana; };

int Entity::getCurrHP() const { return _curr_hp; };

int Entity::getCurrMana() const { return _curr_mana; };

int Entity::getAttack() const { return _attack; };

int Entity::getDefense() const { return _defense; };

int Entity::getSTR() const { return _str; };

int Entity::getINT() const { return _int; };

int Entity::getDEX() const { return _dex; };

int Entity::getLevel() const { return _level; };

int Entity::getMaxExp() const { return _max_exp; };

int Entity::getCurrExp() const { return _curr_exp; };

void Entity::setName(const std::string name) { _name = name; };

void Entity::setAvatar(const int avatar) { _avatar = avatar; };

void Entity::setMaxHP(const int max_hp) { _max_hp = max_hp; };
void Entity::setMaxMana(const int max_mana) { _max_mana = max_mana; };

void Entity::setCurrHP(const int curr_hp) { _curr_hp = curr_hp; };

void Entity::setCurrMana(const int curr_mana) { _curr_mana = curr_mana; };

void Entity::setAttack(const int attack) { _attack = attack; };

void Entity::setDefense(const int defense) { _defense = defense; };

void Entity::setSTR(const int str) { _str = str; };

void Entity::setINT(const int intl) { _int = intl; };

void Entity::setDEX(const int dex) { _dex = dex; };

void Entity::setLevel(const int level) { _level = level; };

void Entity::setMaxExp(const int max_exp) { _max_exp = max_exp; };

void Entity::setCurrExp(const int curr_exp) { _curr_exp = curr_exp; };