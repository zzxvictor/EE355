#include "MyHeader.h"


// constructor 
Monster::Monster()
{
   HP = MONSTER_HP;
   attack = MONSTER_ATTACK;
   defense = MONSTER_DEFENSE;

   //get user Input
   
      do
      {
         
         std::cout<<"Input the age of Monster"<<std::endl;
         std::cin>>age;
         if (std::cin.fail())
         {
            std::cin.clear();
            std::cin.ignore();
         }
         else if ((age>=18)&&(age <=70))
            break;
         else
            std::cout<<"18<age<70"<<std::endl;
      }while(1);

      std::cout<<"please input the firstName of Monster:" <<std::endl;
      std::cin>>firstName;
      std::cout<<"please input the lastName of Monster:" <<std::endl;
      std::cin>>lastName;
      
      int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";

      std::string colorPool[5] = {"Schwarz","Blau", "Rot", "Geld" , "Gruen"};
      color = colorPool[rand()%5];

      X = rand()%16;
      Y = rand()%16;
   
}

Monster::Monster(int x)
{
   HP = MONSTER_HP;
   attack = MONSTER_ATTACK;
   defense = MONSTER_DEFENSE;

   //get user Input
   
      age = rand()%53 + 18;
      std::string firstNamePool[5] = {"Mighty","Invincible","Fast","Old","Cruel"};
      firstName = firstNamePool[rand()%5];
       std::string lastNamePool[7] = {"Monster1","Monster2","Monster3","Monster4","Monster5","Monster6", "Monster7"};
      lastName = lastNamePool[rand()%7];
      int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";

      std::string colorPool[5] = {"Schwarz","Blau", "Rot", "Geld" , "Gruen"};
      color = colorPool[rand()%5];

      X = rand()%16;
      Y = rand()%16;
   
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
	return firstName + "_" + lastName;

}

std::string Monster::getGender()
{
   return gender;
}

int Monster::getAge()
{
   return age;
}

int Monster::getX()
{
   return X;
}

int Monster::getY()
{
   return Y;
}


std::string Monster::getColor()
{
   return color;
}
//SETTER
void Monster::setHP(int newHP)
{
   HP = newHP;
}

void Monster::setXY(int nx, int ny)
{
   X = X + nx;
   Y = Y + ny;
   //std::cout<<X<<", "<<Y<<std::endl;
   if (X<0)
      X = 0;
   if (X>15)
      X = 15;

   if (Y<0)
      Y = 0;
   
   if (Y>15)
      Y = 15;
}

