#ifndef PALICO_H
#define PALICO_H

#define PALICO_HP 50
#define PALICO_ATTACK 5
#define PALICO_CURE 5

class Monster;//FORWARD DECLRATION
class Hunter;
class Palico
{
   private:
      int HP;
      int attack;
   public:
      Palico();
      void AttackMonsters(Monster *rathalos);
      void Cure(Hunter *hunter);
      bool CheckDead();
      int getHP();
      int getAttack();
      void setHP(int newHP);
      void setAttack(int newAttack);
};
#endif
