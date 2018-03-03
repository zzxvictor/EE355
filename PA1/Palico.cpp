#include "MyHeader.h"


//constructor
Palico::Palico()
{
   HP = PALICO_HP;
   attack = PALICO_ATTACK;
}
//Methods
void Palico::AttackMonsters(Monster *rathalos)
{
   if(attack> rathalos->getDefense())
   {
      int MonsterHP = rathalos->getHP();
      int MonsterHP2 = MonsterHP - (attack- rathalos->getDefense());
      rathalos->setHP(MonsterHP2);
      std::cout<<"Your palico attacked rathalos. Rathalos's HP drops from "<<MonsterHP<<" to "<<MonsterHP2<<std::endl;
   }
   else
      std::cout<<"Your palico attacked rathalos. Rathalos's defense is higher than its attack. No HP drops<<"<<std::endl;
}

void Palico::Cure(Hunter *hunter)
{
   int hunterHP = hunter->getHP();
   hunterHP = hunterHP + PALICO_CURE;
   if(hunterHP >= HUNTER_HP)
      hunter->setHP(HUNTER_HP);
   else
       hunter->setHP(hunterHP);
       
   HP+= PALICO_CURE;
   if(HP >= PALICO_HP)
      HP = PALICO_HP;
   std::cout<<"after cure: "<<std::endl;   
   std::cout<<"hunter's HP: "<<hunter->getHP()<<std::endl;
   std::cout<<"Palico's HP: "<<HP<<std::endl;
}

bool Palico::CheckDead()
{
   if(HP>0)
   {
      std::cout<<"Now Palico's HP is: "<<HP<<std::endl;
      return true;
   }
   else
   {
      HP = 0;
      std::cout<<"Rathalos killed your Palico "<<std::endl;
      return false;
   }
}
//GETTER
int Palico::getHP()
{
   return HP;
}
int Palico::getAttack()
{
   return attack;
}

//SETTER
void Palico::setHP(int newHP)
{
   HP = newHP;
}

void Palico::setAttack(int newAttack)
{
   attack = newAttack;
}


