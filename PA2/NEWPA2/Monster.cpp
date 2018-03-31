#include "MyHeader.h"


// constructor 
Monster::Monster()
{
   std::string namePool[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
   HP = MONSTER_HP;
   attack = MONSTER_ATTACK;
   defense = MONSTER_DEFENSE;
   age = rand()%10;
   lastName = namePool[age];
   firstName = MONSTERFIRSTNAME;
}


void Monster::AttackHunter(Hunter *hunter)
{
   if(HP>0)//if monster's HP is lower than 0, do not attack
   {
      if(attack>hunter->getDefense())
      {
         int hunterHP = hunter->getHP();
         int hunterHP2 = hunterHP - (attack- hunter->getDefense());
         hunter->setHP(hunterHP2);
         std::cout<<"Rathalos attacked you. your HP drops from "<<hunterHP<<" to "<<hunterHP2<<std::endl;
      }
      else
         std::cout<<"rathalos attacked you. your defense is higher than its attack. No HP drops<<"<<std::endl;
   }
   else
      std::cout<<"Monster is dead"<<std::endl;
      
	std::cout<<"Monster::AttackHunter needs implementation!"<<std::endl;
}


bool Monster::CheckDead()
{
   if(HP>0)
   {
      std::cout<<"Now Monster's HP is: "<<HP<<std::endl;
      return true;
   }
   else
   {
      HP = 0;
      std::cout<<"Your defeated rathalos, you cna explore this area again "<<std::endl;
      return false;
   }
}

//GETTER
int Monster::getHP()
{
   return HP;
}
int Monster::getAttack()
{
   return attack;
}
int Monster::getDefense()
{
   return defense;
}

std::string Monster::getName()
{
	return firstName + lastName;

}
//SETTER
void Monster::setHP(int newHP)
{
   HP = newHP;
}

