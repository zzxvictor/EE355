#include "MyHeader.h"

//main fucntion
int main()
{
   Run Game;
   Hunter *hunter = new Hunter;
   Monster *rathalos = new Monster;
   Palico *palico = new Palico;
   Game.runGame(hunter, rathalos, palico);
   
}
