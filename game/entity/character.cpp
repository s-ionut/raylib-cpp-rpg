#include "character.hpp"

using namespace game::entity;

ClassType getClassTypeByIndex(int index)
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

std::string getClassNameByType(ClassType type)
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
  m_class = classType;
  initChar();
  setName("NO_NAME");
  setAvatar(0);
};

void Character::initChar()
{
  if(m_class == ClassType::WARRIOR)
  {
    setStats(150, 150, 100, 50, 1, 10);
  }
  else if(m_class == ClassType::ASSASSIN)
  {
    setStats(200, 50, 100, 50, 1, 10);
  }
  else if(m_class == ClassType::SURA)
  {
    setStats(150, 100, 100, 50, 1, 10);
  }
  else if(m_class == ClassType::MAGE)
  {
    setStats(100, 30, 100, 50, 1, 10);
  }
};

void Character::setStats(
  int attack, int defense, int maxHp, int maxMana, int level, int maxExp)
{
  setMaxHP(maxHp);
  setMaxMana(maxMana);

  setAttack(attack);
  setDefense(defense);

  setLevel(level);
  setMaxExp(maxExp);
};

void Character::setClass(ClassType classType) { m_class = classType; }

void Character::calcExp(int givenExp)
{
  auto currExp = getCurrExp();
  auto maxExp  = getMaxExp();

  currExp += givenExp;

  if(currExp >= maxExp)
  {
    levelUp();
  }
};

void Character::levelUp()
{
  auto currLevel = getLevel();
  auto currExp   = getCurrExp();
  auto maxExp    = getMaxExp();

  if(currExp > maxExp)
  {
    setCurrExp(abs(currExp - maxExp));
  }

  setStats(getAttack() + 3,
           getDefense() + 2,
           getMaxHP() + 20,
           getMaxMana() + 5,
           currLevel + 1,
           10 * (currLevel + 1));
};