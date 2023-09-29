#include "character.hpp"

using namespace game::entity;

ClassType game::entity::getClassTypeByIndex(int index)
{
    switch(index) {
        case 0: return ClassType::WARRIOR;
        case 1: return ClassType::ASSASSIN;
        case 2: return ClassType::SURA;
        case 3: return ClassType::MAGE;
        default: throw std::out_of_range("Invalid index");
    }
};

Character::Character()
{
    InitChar();
};

void Character::SetClass(ClassType classType)
{
    _class = classType;
    InitChar();
};

void Character::InitChar()
{
    if(_class == ClassType::WARRIOR)
    {
        SetStats("WARRIOR", 150, 150, 100, 50, 15, 5, 10, 1, 10);
    }
    else if(_class == ClassType::ASSASSIN)
    {
        SetStats("ASSASSIN", 200, 50, 100, 50, 10, 5, 15, 1, 10);
    }
    else if(_class == ClassType::SURA)
    {
        SetStats("SURA", 150, 100, 100, 50, 10, 10, 5, 1, 10);
    }
    else if(_class == ClassType::MAGE)
    {
        SetStats("MAGE", 100, 30, 100, 50, 5, 20, 5, 1, 10);
    }
};

void Character::SetStats(std::string name, int attack, int defense, int max_hp, int max_mana, int str, int intl, int dex, int level, int max_exp)
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
