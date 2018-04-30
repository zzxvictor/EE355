#include "MyHeader.h"


//constructor
Palico::Palico()
{
   HP = PALICO_HP;
   attack = PALICO_ATTACK + swo.getAttack();
   x = 0;
   y = 0;

   
   //get user Input
   while(1)
   {
      std::cout<<"Input the age of Palico"<<std::endl;
      std::cin>>age;
      if (std::cin.fail())
      {
            std::cin.clear();
            std::cin.ignore();
      }
      else
      {
         if ((age>=5)&&(age<=100))
            break;
      }
   }
   std::cout<<"please input the firstName of Palico:" <<std::endl;
   std::cin>>firstName;
   std::cout<<"please input the lastName of Palico:" <<std::endl;
   std::cin>>lastName;

   int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";

   x = rand()%16;
   y = rand()%16;

   //randomly generate color
   std::string colorPool[5] = {"Schwarz","Blau", "Rot", "Geld" , "Gruen"};
   color = colorPool[rand()%5];

}

Palico::Palico(int x)
{
   HP = PALICO_HP;
   attack = PALICO_ATTACK + swo.getAttack();
   x = 0;
   y = 0;

   
   //get user Input
   age = rand()%96 + 5;
      std::string firstNamePool[5] = {"Mighty","Invincible","Fast","Old","Cruel"};
      firstName = firstNamePool[rand()%5];
      std::string lastNamePool[7] = {"Palico1","Palico2","Palico3","Palico4","Palico5","Palico6", "Palico7"};
      lastName = lastNamePool[rand()%7];

   int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";

   x = rand()%16;
   y = rand()%16;

   //randomly generate color
   std::string colorPool[5] = {"Schwarz","Blau", "Rot", "Geld" , "Gruen"};
   color = colorPool[rand()%5];

}

//Methods
void Palico::AttackMonsters(Monster *rathalos)
{
   //valid only when palico is alive
   if (HP > 0)
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
   else
      std::cout<<"Palico is dead, cannot attack Monster";
}



void Palico::Cure(Hunter *hunter)
{
   if (HP > 0)
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
   else
      std::cout<<"Palico is dead, cannot cure";
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

std::string Palico::getName()
{
   return firstName+lastName;
}

int Palico::getAge()
{
   return age;
}

std::string Palico::getGender()
{
   return gender;
}

int Palico::getX()
{
   return x;
}

int Palico::getY()
{
   return y;
}

std::string Palico::getColor()
{
   return color;
}

Sword Palico::getSword()
{
   return swo;
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


void Palico::setXY(int nx, int ny)
{
   x = x + nx;
   y = y + ny;
   if (x<0)
      x = 0;

   if (x>15)
      x = 15;

   if (y<0)
      y = 0;
   
   if (y>15)
      y = 15;
}


