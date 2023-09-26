#pragma once

// system specific
#include "etc/system_includes.h"

namespace game {
    namespace entity {
        class Entity
        {
            public:
                Entity();
                ~Entity() {};

                void Update();

            protected:
                void LevelUp();

                std::string GetName() const;

                int GetMaxHP() const;
                int GetMaxMana() const;
                int GetCurrHP() const;
                int GetCurrMana() const;

                int GetAttack() const;
                int GetDefense() const;
                
                int GetSTR() const;
                int GetINT() const;
                int GetDEX() const;
                
                int GetLevel() const;
                int GetMaxExp() const;
                int GetCurrExp() const;

                std::string SetName(const std::string name);

                void SetMaxHP(const int max_hp);
                void SetMaxMana(const int max_mana);
                void SetCurrHP(const int curr_hp);
                void SetCurrMana(const int curr_mana);

                void SetAttack(const int attack);
                void SetDefense(const int defense);
                
                void SetSTR(const int str);
                void SetINT(const int intl);
                void SetDEX(const int dex);
                
                void SetLevel(const int level);
                void SetMaxExp(const int max_exp);
                void SetCurrExp(const int curr_exp);
            
            private:
                virtual void CalcAttack() {};
                virtual void CalcDefense() {};
                void CalcExp(int given_exp);
                
                std::string _name;

                int _max_hp;
                int _max_mana;
                int _curr_hp;
                int _curr_mana;
                
                int _attack;
                int _defense;

                int _str;
                int _int;
                int _dex;

                int _level;
                int _max_exp;
                int _curr_exp;
        };
    } // namespace entity
} // namespce game