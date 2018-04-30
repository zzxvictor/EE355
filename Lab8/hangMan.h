#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <time.h>
#define SIZE 10



class Hangman
{
private:
	bool flag;
	int maxAttempt;
	char * goldenWord;
	char * wordBank[SIZE] = {"EE355","EE250","WRIT150","PSYC100","EE330","EE155","PHYS153","REL125gp","MATH245","ITP105"};
public:
	friend class Debug;
	Hangman();
	void terminate();
	void setAttempts(int newAttempt);
	void setWord();
	int getAttempts();
	char* getWord();
	void runGame();

};

class Debug
{

};

class TestList
{

};
#endif 