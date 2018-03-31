#ifndef PALICO_H
#define PALICO_H

#define PALICO_HP 50
#define PALICO_ATTACK 5
#define PALICOFIRSTNAME "Yao Xiao "
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

      std::string gender;
      Sword swo;
      std::string color;
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
