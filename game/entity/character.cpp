#include "character.hpp"

using namespace game::entity;

ClassType game::entity::getClassTypeByIndex(int index)
{
  switch(index)
  {
    case 0 : return ClassType::WARRIOR;
    case 1 : return ClassType::ASSASSIN;
    case 2 : return ClassType::SURA;
    case 3 : return ClassType::MAGE;
    default : throw std::out_of_range("Invalid index");
  }
};

std::string game::entity::getClassNameByType(ClassType type)
{
  switch(type)
  {
    case ClassType::WARRIOR : return "Warrior";
    case ClassType::ASSASSIN : return "Assassin";
    case ClassType::SURA : return "Sura";
    case ClassType::MAGE : return "Mage";
    default : throw std::out_of_range("Invalid index");
  }
};

Character::Character(ClassType classType)
{
  _class = classType;
  initChar();
  setName("NO_NAME");
  setAvatar(0);
};

void Character::initChar()
{
  if(_class == ClassType::WARRIOR)
  {
    setStats(150, 150, 100, 50, 15, 5, 10, 1, 10);
  }
  else if(_class == ClassType::ASSASSIN)
  {
    setStats(200, 50, 100, 50, 10, 5, 15, 1, 10);
  }
  else if(_class == ClassType::SURA)
  {
    setStats(150, 100, 100, 50, 10, 10, 5, 1, 10);
  }
  else if(_class == ClassType::MAGE)
  {
    setStats(100, 30, 100, 50, 5, 20, 5, 1, 10);
  }
};

void Character::setStats(int attack,
                         int defense,
                         int max_hp,
                         int max_mana,
                         int str,
                         int intl,
                         int dex,
                         int level,
                         int max_exp)
{
  setMaxHP(max_hp);
  setMaxMana(max_mana);

  setAttack(attack);
  setDefense(defense);

  setSTR(str);
  setINT(intl);
  setDEX(dex);

  setLevel(level);
  setMaxExp(max_exp);
};

void Character::setClass(ClassType class_type) { _class = class_type; }