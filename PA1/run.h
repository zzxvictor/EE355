#ifndef RUN_H
#define RUN_H

#define ENERGY_LOSS 10
class Run
{
   private:
     bool hunterAlive;//flag of hunter's status
     bool palicoAlive;//flag of palico's status
     bool monsterAlive;//flag of monster's status
     
     void checkDead(Hunter *hunter, Monster *rathalos, Palico *palico);
     void printWelcome();
     bool findRathalos(Hunter *hunter);
     bool readUserInput(int mode);
     int rathalosAttack();
     
   public:
     Run();//constructor
     void runGame(Hunter *hunter, Monster *rathalos, Palico *palico);
     
     
};

#endif
