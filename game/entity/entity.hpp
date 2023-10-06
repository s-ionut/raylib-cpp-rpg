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

                std::string getName() const;

                int getMaxHP() const;
                int getMaxMana() const;
                int getCurrHP() const;
                int getCurrMana() const;

                int getAttack() const;
                int getDefense() const;
                
                int getSTR() const;
                int getINT() const;
                int getDEX() const;
                
                int getLevel() const;
                int getMaxExp() const;
                int getCurrExp() const;
                void setName(const std::string name);

                void setMaxHP(const int max_hp);
                void setMaxMana(const int max_mana);
                void setCurrHP(const int curr_hp);
                void setCurrMana(const int curr_mana);

                void setAttack(const int attack);
                void setDefense(const int defense);
                
                void setSTR(const int str);
                void setINT(const int intl);
                void setDEX(const int dex);
                
                void setLevel(const int level);
                void setMaxExp(const int max_exp);
                void setCurrExp(const int curr_exp);
            protected:
                void levelUp();
                
            private:
                virtual void calcAttack() {};
                virtual void calcDefense() {};
                void calcExp(int given_exp);
                
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