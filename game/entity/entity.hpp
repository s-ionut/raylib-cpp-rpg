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

      void Update();

      std::string getName() const;
      int         getAvatar() const;

      int getMaxHP() const;
      int getMaxMana() const;

      int getAttack() const;
      int getDefense() const;

      int  getLevel() const;
      int  getMaxExp() const;
      int  getCurrExp() const;
      void setName(const std::string name);
      void setAvatar(const int avatar);

      void setMaxHP(const int maxHp);
      void setMaxMana(const int maxMana);

      void setAttack(const int attack);
      void setDefense(const int defense);

      void setLevel(const int level);
      void setMaxExp(const int maxExp);
      void setCurrExp(const int currExp);

    protected:
      void levelUp();

    private:
      virtual void calcAttack() {};
      virtual void calcDefense() {};
      void         calcExp(int givenExp);

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