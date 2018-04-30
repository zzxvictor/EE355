#include "MyHeader.h"

//constructor
Hunter::Hunter()
{
      energy = HUNTER_ENERGY;
      HP = HUNTER_HP;

      //add equipments 
      attack = HUNTER_ATTACK + swo.getAttack();
      defense = HUNTER_DEFENSE + equ.getDefense();

      //get user Input
      do
      {
         
         std::cout<<"Input the age of Hunter"<<std::endl;
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

      std::cout<<"please input the firstName of Hunter:" <<std::endl;
      std::cin>>firstName;
      std::cout<<"please input the lastName of Hunter:" <<std::endl;
      std::cin>>lastName;

      int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";
      //randomly generate color
      std::string colorPool[5] = {"Schwarz","Blau", "Rot", "Geld" , "Gruen"};
      color = colorPool[rand()%5];

      //randomly generate x and y
      x = rand()%16;
      y = rand()%16;
      
}
Hunter::Hunter(int x)
{
         energy = HUNTER_ENERGY;
      HP = HUNTER_HP;

      //add equipments 
      attack = HUNTER_ATTACK + swo.getAttack();
      defense = HUNTER_DEFENSE + equ.getDefense();

      //get user Input
      age = rand()%63 + 18;
      std::string firstNamePool[5] = {"Mighty","Invincible","Fast","Old","Cruel"};
      firstName = firstNamePool[rand()%5];
      std::string lastNamePool[7] = {"Hunter1","PHunter2","Hunter3","Hunter4","Hunter5","Hunter6", "Hunter7"};
      lastName = lastNamePool[rand()%7];
      int temp = rand()%10;
      if (temp < 5)
         gender = "Male";
      else
         gender = "Female";
      //randomly generate color
      std::string colorPool[5] = {"Schwarz","Blau", "Rot", "Geld" , "Gruen"};
      color = colorPool[rand()%5];

      //randomly generate x and y
      x = rand()%16;
      y = rand()%16;
}


//methods 
void Hunter::AttackMonsters(Monster *rathalos)
{
   if(HP>0)//do this only when HP is higher than 0
   {
      if(attack>rathalos->getDefense())
      {
         int MonsterHP = rathalos->getHP();
         int MonsterHP2 = MonsterHP - (attack- rathalos->getDefense());
         rathalos->setHP(MonsterHP2);
         std::cout<<"You attacked rathalos. Rathalos's HP drops from "<<MonsterHP<<" to "<<MonsterHP2<<std::endl;
      }
      else
         std::cout<<"You attacked rathalos. Rathalos's defense is higher than your attack. No HP drops<<"<<std::endl;
   }
}

void Hunter::DefendMonsters(Monster *rathalos)
{
   //only valid when monster is still alive
   if(rathalos->getHP()>0)
   {
      if(2*defense< rathalos->getAttack())
      {
         int HP2 = HP;
         HP = HP2 - (rathalos->getAttack() - 2*defense);
         std::cout<<"You are attacked by rathalos. your HP drops from "<<HP2<<" to "<<HP<<std::endl;
      }
      else
         std::cout<<"rathalos attacked your. your defense is higher than Rathalos's attack. No HP drops<<"<<std::endl;
   }
}

void Hunter::DefendMonsters(int monsterAttack)
{
   if(2*defense< monsterAttack)
      {
         int HP2 = HP;
         HP = HP2 - (monsterAttack - 2*defense);
         std::cout<<"You are attacked by rathalos. your HP drops from "<<HP2<<" to "<<HP<<std::endl;
      }
      else
         std::cout<<"rathalos attacked your. your defense is higher than Rathalos's attack. No HP drops<<"<<std::endl;
}

bool Hunter::CheckDead()
{
   if(HP>0)
   {
      std::cout<<"Now your HP is: "<<HP<<std::endl;
      return true;
   }
   else
   {
      HP = 0;
      std::cout<<"Your faint, now return back to village "<<std::endl;
      return false;
   }
}


//getter functions
int Hunter::getEnergy()
{
   return energy;
}
int Hunter::getHP()
{
   return HP;
}
int Hunter::getAttack()
{
   return attack;
}
int Hunter::getDefense()
{
   return defense;
}


std::string Hunter::getName()
{
   return firstName + "_" +lastName;
}

int Hunter::getAge()
{
   return age;
}

std::string Hunter::getGender()
{
   return gender;
}

std::string Hunter::getColor()
{
   return color;
}

int Hunter::getX()
{
   return x;
}
int Hunter::getY()
{
   return y;
}


Sword Hunter::getSword()
{
   return swo;
}
Equipment Hunter::getEqu()
{
   return equ;
}
//setter functions
void Hunter::setEnergy(int newEnergy)
{
   energy = newEnergy;
}

void Hunter::setHP(int newHP)
{
   HP = newHP;
}

void Hunter::setAttack(int newAttack)
{
   attack = newAttack;
}

void Hunter::setDefense(int newDefense)
{
   defense = newDefense;
}

void Hunter::setXY(int nx, int ny)
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