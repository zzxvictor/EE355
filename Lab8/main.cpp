#include "hangMan.h"

int main()
{
	srand(time(0));
	Hangman *h1 = new Hangman();
	h1->runGame();
}
