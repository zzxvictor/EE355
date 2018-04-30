#ifndef MONSTER_H
#define MONSTER_H

#define MONSTER_HP 100
#define MONSTER_ATTACK 40
#define MONSTER_DEFENSE 1

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
      std::string gender;
      std::string color;
      int X;
      int Y;

   public:
      Monster();
      Monster(int x);
      void AttackHunter(Hunter *hunter);
      void AttackPalico(Palico *palico);
      bool CheckDead();

      int getHP();
      int getAttack();
      int getDefense();
      std::string getName();
      std::string getGender();
      std::string getColor();
      int getAge();
      int getX();
      int getY();

      void setHP(int newHP);
      void setXY(int nx, int ny);
};
#endif
