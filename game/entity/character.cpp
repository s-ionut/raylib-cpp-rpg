#include "character.hpp"

using namespace game::entity;

Character::Character()
{
    InitChar();
};

void Character::SetClass(ClassType class)
{
    _class = class;
};

void Character::InitChar()
{
    if(_class == ClassType::WARRIOR)
    {
        SetStats("WARRIOR", 100, 50, 15, 5, 10, 1, 10);
    }
    else if(_class == ClassType::ASSASSIN)
    {
        SetStats("ASSASSIN", 100, 50, 10, 5, 15, 1, 10);
    }
    else if(_class == ClassType::SURA)
    {
        SetStats("SURA", 100, 50, 10, 10, 5, 1, 10);
    }
    else if(_class == ClassType::MAGE)
    {
        SetStats("MAGE", 100, 50, 5, 20, 5, 1, 10);
    }
};

void Character::SetStats(std::string name, int max_hp, int max_mana, int str, int intl, int dex, int level, int max_exp)
{                
    SetName(name);

    SetMaxHP(max_hp);
    SetMaxMana(max_mana);

    SetAttack(attack);
    SetDefense(defense);

    SetSTR(str);
    SetINT(intl);
    SetDEX(dex);

    SetLevel(level);
    SetMaxExp(max_exp);
};