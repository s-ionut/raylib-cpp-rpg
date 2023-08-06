#include "entity.hpp"

using namespace core::entity;

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