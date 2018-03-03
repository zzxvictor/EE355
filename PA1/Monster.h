#ifndef MONSTER_H
#define MONSTER_H

#define MONSTER_HP 100
#define MONSTER_ATTACK 20
#define MONSTER_DEFENSE 1

class Hunter;//FORWARD DECLARATION
class Palico;
class Monster
{
   private:
      int HP;
      int attack;
      int defense;
   public:
      Monster();
      void AttackHunter(Hunter *hunter);
      void AttackPalico(Palico *palico);
      bool CheckDead();
      int getHP();
      int getAttack();
      int getDefense();
      void setHP(int newHP);
      void setAttack(int newAttack);
      void setDefense(int newDefense);
};
#endif
