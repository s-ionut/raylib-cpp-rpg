#include "entity.hpp"

using namespace game::entity;

Entity::Entity()
{
    _level = 1;
    _curr_exp = 0;
    _curr_hp = _max_hp;
    _curr_mana = _max_mana;
};


void Entity::Update()
{

};

void Entity::LevelUp()
{
    _level += 1;
    _curr_exp = 0;

    if(_curr_exp > _max_exp)
    {
        _curr_exp = (_curr_exp - _max_exp);
    }

    _max_exp = 10 * _level;
};

void Entity::CalcExp(int given_exp)
{
    _curr_exp += given_exp;

    if(_curr_exp >= _max_exp)
    {
        LevelUp();
    }
};

std::string Entity::GetName() const
{
    return _name;
}

int Entity::GetMaxHP() const
{
    return _max_hp;
};

int Entity::GetMaxMana() const
{
    return _max_mana;
};

int Entity::GetCurrHP() const
{
    return _curr_hp;
};

int Entity::GetCurrMana() const
{
    return _curr_mana;
};

int Entity::GetAttack() const
{
    return _attack;
};

int Entity::GetDefense() const
{
    return _defense;
};

int Entity::GetSTR() const
{
    return _str;
};

int Entity::GetINT() const
{
    return _int;
};

int Entity::GetDEX() const
{
    return _dex;
};

int Entity::GetLevel() const
{
    return _level;
};

int Entity::GetMaxExp() const
{
    return _max_exp;
};

int Entity::GetCurrExp() const
{
    return _curr_exp;
};

void Entity::SetName(const std::string name)
{
    _name = name;
};

void Entity::SetMaxHP(const int max_hp)
{
    _max_hp = max_hp;
};
void Entity::SetMaxMana(const int max_mana)
{
    _max_mana = max_mana;
};

void Entity::SetCurrHP(const int curr_hp)
{
    _curr_hp = curr_hp;
};

void Entity::SetCurrMana(const int curr_mana)
{
    _curr_mana = curr_mana;
};

void Entity::SetAttack(const int attack)
{
    _attack = attack;
};

void Entity::SetDefense(const int defense)
{
    _defense = defense;
};

void Entity::SetSTR(const int str)
{
    _str = str;
};

void Entity::SetINT(const int intl)
{
    _int = intl;
};

void Entity::SetDEX(const int dex)
{
    _dex = dex;
};

void Entity::SetLevel(const int level)
{
    _level = level;
};

void Entity::SetMaxExp(const int max_exp)
{
    _max_exp = max_exp;
};

void Entity::SetCurrExp(const int curr_exp)
{
    _curr_exp = curr_exp;
};