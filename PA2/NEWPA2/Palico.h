#ifndef PALICO_H
#define PALICO_H

#define PALICO_HP 50
#define PALICO_ATTACK 5
#define PALICO_CURE 5

class Monster;//FORWARD DECLRATION
class Hunter;
class Sword;

class Palico
{
   private:
      int HP;
      int attack;
      int age;
      int x;
      int y;

      std::string gender;
      std::string color;
      Sword swo;
      std::string lastName;
      std::string firstName;

   public:
      Palico();
      void AttackMonsters(Monster *rathalos);
      void Cure(Hunter *hunter);
      bool CheckDead();
      int getHP();
      int getAttack();
      std::string getName();
      int getAge();
      std::string getGender();
      void setHP(int newHP);
      void setAttack(int newAttack);
};
#endif
