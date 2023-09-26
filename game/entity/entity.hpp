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


                void LevelUp();
                virtual void CalcAttack() {};
                virtual void CalcDefense() {};
                void CalcExp(int given_exp);

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

                std::string SetName() const;

                int SetMaxHP() const;
                int SetMaxMana() const;
                int SetCurrHP() const;
                int SetCurrMana() const;

                int SetAttack() const;
                int SetDefense() const;
                
                int SetSTR() const;
                int SetINT() const;
                int SetDEX() const;
                
                int SetLevel() const;
                int SetMaxExp() const;
                int SetCurrExp() const;
        };
    } // namespace entity
} // namespce game