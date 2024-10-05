#pragma once

namespace game
{
  namespace entity
  {
    class Entity
    {
    public:
      Entity();
      ~Entity() {};

      std::string getName() const { return m_name; };
      int         getAvatar() const { return m_avatar; };
      int         getMaxHP() const { return m_maxHp; };
      int         getMaxMana() const { return m_maxMana; };
      int         getAttack() const { return m_attack; };
      int         getDefense() const { return m_defense; };
      int         getLevel() const { return m_level; };
      int         getMaxExp() const { return m_maxExp; };
      int         getCurrExp() const { return m_currExp; };

      void setName(const std::string name) { m_name = name; };
      void setAvatar(const int avatar) { m_avatar = avatar; };
      void setMaxHP(const int maxHp) { m_maxHp = maxHp; };
      void setMaxMana(const int maxMana) { m_maxMana = maxMana; };
      void setAttack(const int attack) { m_attack = attack; };
      void setDefense(const int defense) { m_defense = defense; };
      void setLevel(const int level) { m_level = level; };
      void setMaxExp(const int maxExp) { m_maxExp = maxExp; };
      void setCurrExp(const int currExp) { m_currExp = currExp; };

    private:
      std::string m_name;
      int         m_avatar;

      int m_maxHp;
      int m_maxMana;

      int m_attack;
      int m_defense;

      int m_level;
      int m_maxExp;
      int m_currExp;
    };
  } // namespace entity
} // namespce game