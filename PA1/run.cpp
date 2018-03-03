#include "MyHeader.h"
//constructor
Run::Run()
{
   hunterAlive = true;
   palicoAlive = true;
   monsterAlive = true;
}

/************************************************************************
**************************Runing function********************************
*************************************************************************/
void Run::runGame(Hunter *hunter, Monster *rathalos, Palico *palico)
{
   Run::printWelcome();//welcome interface
   bool hunterChoice;
   bool palicoChoice;
   int rathalosChoice;
   int killNum = 0;
   bool defendFlag = false;
   
   while(1)//outer loop, used to run the game
   {
      std::cout<<"You have killed "<<killNum<<" rathalos"<<std::endl;
      if(Run::findRathalos(hunter))//if find rathalos, do the rest of the things
      {
         //inner loopm used in a single battle
         while(1)
         {  
            std::cout<<" you are about to _____ (attack/defense)"<<std::endl;
            hunterChoice = Run::readUserInput(1);
            
            std::cout<<"****************************************"<<std::endl;
            /****hunter attack/defend the monster***/
            if(hunterChoice)//attack
            {
               hunter->AttackMonsters(rathalos);
            }
            else//defend
            {
               defendFlag = true;
            }
            
            /************************/
            /****palico attack*****/
            /************************/
            if(palicoAlive)//if palico is dead, then skip this section
            {
               std::cout<<"Now your palico should attack/cure"<<std::endl;
               palicoChoice = Run::readUserInput(2);
               if(palicoChoice)//attack
               {   
                  palico->AttackMonsters(rathalos);
               }
               else//cure
               {
                  palico->Cure(hunter);
               }
            }
            
            /************************/
            /****rathalos attack*****/
            /************************/
            rathalosChoice = rathalosAttack();
            if(rathalosChoice == 1)//monster attacks hunter
            {
               if(!defendFlag)//attack
                  rathalos->AttackHunter(hunter);
               else//based on attack/defend choice made by user
               {
                  hunter->DefendMonsters(rathalos);
                  defendFlag = false;
               }
            }
            else if (rathalosChoice == 2)//monster attacks palico
            {
               rathalos->AttackPalico(palico);
            }
            else
            {
               ;
            }
         
            //check dead
            Run::checkDead(hunter, rathalos, palico);
            //check if need to jump out of inner loop
            if(monsterAlive == false)//monster is defeated;
            {
               rathalos->setHP(MONSTER_HP);//refresh, another monster
               killNum++;
               std::cout<<"****************************************"<<std::endl;
               break;//ready for the next round
            }
            //check hunter's status
            if((hunterAlive == false)||(hunter->getEnergy() <=0))
            {
               std::cout<<"You have killed "<< killNum<<" rathalos, Good Game!"<<std::endl;
               std::cout<<"****************************************"<<std::endl;
               break;
            }
            
            
         }
      //end of the inner loop, because you are dead/ the rathalos is dead
      }
      if((hunterAlive == false)||(hunter->getEnergy() <=0))//if you're dead/faint, game over
         break;
   }
}


//other helper functions
/***********************************************************************
************************************************************************
***********************************************************************/

/*****************************************************************
   check status of hunter, rathalos and palico and update the flags
******************************************************************/

void Run::checkDead(Hunter *hunter, Monster *rathalos, Palico *palico)
{
   std::cout<<"***************************************************"<<std::endl;
   hunterAlive = hunter->CheckDead();
   monsterAlive = rathalos->CheckDead();
   palicoAlive = palico->CheckDead();
   //check enenrgy
   std::cout<<"Hunter's energy left: "<< hunter->getEnergy() <<std::endl;
   std::cout<<"***************************************************"<<std::endl;
}

/*****************************************************************
   welcome interface, used in the very beginning of the program
******************************************************************/

void Run::printWelcome()
{
   std::string welcome1 = "|     |     |  _____   |        ____    ___      |   |     ____    "; 
   std::string welcome2 = " |   | |   |  |_____|  |       |       |   |    ||   ||   |____|   ";              
   std::string welcome3 = "  | |   | |   |        |       |       |   |   |  | |  |  |        ";
   std::string welcome4 = "   |     |    |_____/  |_____/ |____/  |___|  |    |    | |____/   ";
   
   std::cout<<"Welcome to text-based monster hunter world. You, the hunter, are assigned a task to kill as many Rathalos as possible!"<<std::endl;
   std::cout<<welcome1<<std::endl;
   std::cout<<welcome2<<std::endl;
   std::cout<<welcome3<<std::endl;
   std::cout<<welcome4<<std::endl;
}

/*****************************************************************
   randomly generate number to decide if find a rathalos
   return true if find one
   return false if find nothing
******************************************************************/

bool Run::findRathalos(Hunter *hunter)
{
   int number = rand()%10;//0 - 9, ten numbers in total
   int energy = hunter->getEnergy();
   hunter->setEnergy(energy-ENERGY_LOSS);//constant defined in the headerfile
   std::cout<<"You are walking to find a rathalos"<<std::endl;
   if(number >= 2)
   {
       std::cout<<"Now you have found Rathalos";
       return true;
   }
   else
   {
       std::cout<<"You didn't find rathalos "<<std::endl;
       return false;
   }
}


/*****************************************************************************
   read user input, mode 1 for reading huner input, 2 for reading palico input
   mode 1: return true for attack, return false for defense
   mode 2: return true for attack, return false for cure
******************************************************************************/
bool Run::readUserInput(int mode)
{
   std::string userInput;
   if(mode == 1)//read input for hunter
   {
      do 
      {
         std::cin>>userInput;
      }while(userInput.compare("attack") && userInput.compare("defense"));
      
      
      if(!userInput.compare("attack"))
         return true;//attack
      else 
         return false;//defense
      
   }
   else if (mode == 2)//read input for palico
   {
      do 
      {
         std::cin>>userInput;
      }while(userInput.compare("attack") && userInput.compare("cure"));
      
      
      if(!userInput.compare("attack"))
         return true;//attack
      else 
         return false;//cure
   }
   else
   {
      std::cout<<"error: unknown mode! "<<std::endl;
   }
   
}
/*****************************************************************
   randomly generate number to decide if rathalos gonna attack
   return 1 if rathalos attacks hunter
   return 2 if attacks palico
   return 3 if monster does nothing
******************************************************************/

int Run::rathalosAttack()
{
   int number = rand()%10;//0 - 9, ten numbers in total
   if(number >= 3)
   {
       //std::cout<<"Monster attacked you"<<std::endl;
       return 1;
   }
   else if(number>=1 )
   {
       //std::cout<<"Monster attacked your palico"<<std::endl;
       return 2;
   }
   else
   {
      std::cout<<"Monster did nothing"<<std::endl;
      return 0;
   }
}

