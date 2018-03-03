#ifndef HUNTER_H
#define HUNTER_H

#define HUNTER_HP 100
#define HUNTER_ENERGY 100
#define HUNTER_ATTACK 10
#define HUNTER_DEFENSE 4

class Monster;//FORWARD DECLARATION
class Hunter
{
   private:
      int energy;
      int HP;
      int attack;
      int defense;
   public:
      Hunter();
      void AttackMonsters(Monster *rathalos);
      void DefendMonsters(Monster *rathalos);
      bool CheckDead();
      int getEnergy();
      int getHP();
      int getAttack();
      int getDefense();
      void setEnergy(int newEnergy);
      void setHP(int newHP);
      void setAttack(int newAttack);
      void setDefense(int newDefense);
};

#endif
