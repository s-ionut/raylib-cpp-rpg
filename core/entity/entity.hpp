#pragma once


namespace core {
    namespace entity {
        class Entity
        {
            public:
                Entity();
                ~Entity();

                void Update();
            private:
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
        };
    } // namespace entity
} // namespce core