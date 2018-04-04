#ifndef HUNTER_H
#define HUNTER_H

#define HUNTER_HP 100
#define HUNTER_ENERGY 100
#define HUNTER_ATTACK 10
#define HUNTER_DEFENSE 4
class Monster;//FORWARD DECLARATION
class Sword;
class Equipment;

class Hunter
{
   private:
      int energy;
      int HP;
      int attack;
      int defense;
      Sword swo;
      Equipment equ;
      int x;
      int y;
      int age;
      std::string color;
      std::string firstName;
      std::string lastName;
      std::string gender;
      

   public:
      Hunter();
      void AttackMonsters(Monster *rathalos);
      void DefendMonsters(Monster *rathalos);
      void DefendMonsters(int monsterAttack);
      bool CheckDead();
      int getEnergy();
      int getHP();
      int getAttack();
      int getDefense();
      std::string getName();
      int getAge();
      std::string getGender();
      int getX();
      int getY();
      std::string getColor();



      void setEnergy(int newEnergy);
      void setHP(int newHP);
      void setAttack(int newAttack);
      void setDefense(int newDefense);
};

#endif
