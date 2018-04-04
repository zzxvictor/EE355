#include "MyHeader.h"


// constructor 
Monster::Monster()
{
   HP = MONSTER_HP;
   attack = MONSTER_ATTACK;
   defense = MONSTER_DEFENSE;

   //get user Input
   
         while(1)
      {
         std::cout<<"Input the age of Monster"<<std::endl;
         std::cin>>age;
         if (!std::cin)
         {
            std::cout<<"bad input, try again!"<<std::endl;
         }
         else
         {
            if ((age>=18)&&(age<=70))
               break;
         }
      }
      std::cout<<"please input the firstName of Monster:" <<std::endl;
      std::cin>>firstName;
      std::cout<<"please input the lastName of Monster:" <<std::endl;
      std::cin>>lastName;
      
      int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";
   
}



void Monster::AttackHunter(Hunter *hunter)
{
   if(HP>0)//if monster's HP is lower than 0, do not attack
   {
      hunter->DefendMonsters(attack);

   }
   else
      std::cout<<"Monster is dead"<<std::endl;
}

void Monster::AttackPalico(Palico *palico)
{
   if(HP>0)
   {
      int PalicoHP = palico->getHP();
      if(PalicoHP>0)
      {
         int PalicoHP2 = PalicoHP - attack;
         palico->setHP(PalicoHP2);
         std::cout<<"Rathalos attacked palico. its HP drops from "<<PalicoHP<<" to "<<PalicoHP2<<std::endl;
      }
   }
   else
      std::cout<<"Monster is dead<<"<<std::endl;

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

