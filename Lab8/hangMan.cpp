#include "hangMan.h"



Hangman::Hangman()
{
	//by default maxAttempt = 10
	maxAttempt = 10;

	flag = true;
	setWord();
}

void Hangman::terminate()
{
	if (maxAttempt<= 0)
		flag = false;
}

void Hangman::setAttempts(int newAttempt)
{
	maxAttempt = newAttempt;
}

void Hangman::setWord()
{
	int index = rand()%SIZE;
	goldenWord = wordBank[index];
}

int Hangman::getAttempts()
{
	return  maxAttempt;
}

char* Hangman::getWord()
{
	return goldenWord;
}

void Hangman::runGame()
{

	while (flag)
	{
		std::cout<<"The game is running"<<std::endl;
		std::cout<<"the word is: "<<goldenWord<<std::endl;
		
		terminate();
	}
}