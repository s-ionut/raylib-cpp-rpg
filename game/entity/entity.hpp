#pragma once

// system specific
#include "etc/system_includes.h"

// core specific
#include "core/serialization/serializable.hpp"

namespace game {
    namespace entity {
        enum class ClassType
        {
            WARRIOR = 0,
            ASSASSIN,
            SURA,
            MAGE,
            COUNT,
            NONE
        };

        class Entity : public core::serialization::SerializableBase<Entity>
        {
            public:
                Entity();
                ~Entity() {};

                void Update();

                std::string getName() const;
                int getAvatar() const;

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
                void setAvatar(const int avatar);

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
                
                ClassType _class = ClassType::NONE;

                void serialize(std::ostream& out) const override
                {
                    out.write(reinterpret_cast<const char*>(&_class), sizeof(_class));
                    out.write(reinterpret_cast<const char*>(&_name), sizeof(_name));
                    out.write(reinterpret_cast<const char*>(&_avatar), sizeof(_avatar));
                    out.write(reinterpret_cast<const char*>(&_max_hp), sizeof(_max_hp));
                    out.write(reinterpret_cast<const char*>(&_max_mana), sizeof(_max_mana));
                    out.write(reinterpret_cast<const char*>(&_curr_hp), sizeof(_curr_hp));
                    out.write(reinterpret_cast<const char*>(&_curr_mana), sizeof(_curr_mana));
                    out.write(reinterpret_cast<const char*>(&_attack), sizeof(_attack));
                    out.write(reinterpret_cast<const char*>(&_defense), sizeof(_defense));
                    out.write(reinterpret_cast<const char*>(&_str), sizeof(_str));
                    out.write(reinterpret_cast<const char*>(&_int), sizeof(_int));
                    out.write(reinterpret_cast<const char*>(&_dex), sizeof(_dex));
                    out.write(reinterpret_cast<const char*>(&_level), sizeof(_level));
                    out.write(reinterpret_cast<const char*>(&_max_exp), sizeof(_max_exp));
                    out.write(reinterpret_cast<const char*>(&_curr_exp), sizeof(_curr_exp));
                };
                void deserialize(std::istream& in) override
                {
                    in.read(reinterpret_cast<char*>(&_class), sizeof(_class));
                    in.read(reinterpret_cast<char*>(&_name), sizeof(_name));
                    in.read(reinterpret_cast<char*>(&_avatar), sizeof(_avatar));
                    in.read(reinterpret_cast<char*>(&_max_hp), sizeof(_max_hp));
                    in.read(reinterpret_cast<char*>(&_max_mana), sizeof(_max_mana));
                    in.read(reinterpret_cast<char*>(&_curr_hp), sizeof(_curr_hp));
                    in.read(reinterpret_cast<char*>(&_curr_mana), sizeof(_curr_mana));
                    in.read(reinterpret_cast<char*>(&_attack), sizeof(_attack));
                    in.read(reinterpret_cast<char*>(&_defense), sizeof(_defense));
                    in.read(reinterpret_cast<char*>(&_str), sizeof(_str));
                    in.read(reinterpret_cast<char*>(&_int), sizeof(_int));
                    in.read(reinterpret_cast<char*>(&_dex), sizeof(_dex));
                    in.read(reinterpret_cast<char*>(&_level), sizeof(_level));
                    in.read(reinterpret_cast<char*>(&_max_exp), sizeof(_max_exp));
                    in.read(reinterpret_cast<char*>(&_curr_exp), sizeof(_curr_exp));
                    in.read(reinterpret_cast<char*>(&_curr_exp), sizeof(_curr_exp));
                    in.read(reinterpret_cast<char*>(&_curr_exp), sizeof(_curr_exp));
                };
                
            private:
                virtual void calcAttack() {};
                virtual void calcDefense() {};
                void calcExp(int given_exp);
                
                
                std::string _name;
                int _avatar;

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