#ifndef MONSTER_H
#define MONSTER_H

#define MONSTER_HP 100
#define MONSTER_ATTACK 20
#define MONSTER_DEFENSE 1
#define MONSTERFIRSTNAME "Prof. Shahin No."

class Hunter;//FORWARD DECLARATION
class Palico;

class Monster
{
   private:
      int HP;
      int attack;
      int defense;
      int age;
      std::string lastName;
      std::string firstName;

   public:
      Monster();
      
      void AttackHunter(Hunter *hunter);
      bool CheckDead();

      int getHP();
      int getAttack();
      int getDefense();
      std::string getName();

      void setHP(int newHP);
      
};
#endif
