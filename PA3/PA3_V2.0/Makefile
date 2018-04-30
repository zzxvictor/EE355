# Makefile for PA2
# variables 
CC = g++ 

CFLAGS = -std=c++11  -c -Wall

all: PA2 clean
	./PA2
PA2: Item.o Hunter.o Monster.o Palico.o Point.o Monsterbook.o HunterBook.o PalicoBook.o bmplib.o runGame.o Champion.o GUI.o PA2_main.o
	$(CC) Item.o Hunter.o Monster.o Palico.o Point.o Monsterbook.o HunterBook.o PalicoBook.o bmplib.o runGame.o Champion.o GUI.o PA2_main.o -o PA2

Item.o:Item.cpp
	$(CC) $(CFLAGS) Item.cpp 

Hunter.o: Hunter.cpp
	$(CC) $(CFLAGS) Hunter.cpp 
   
Monster.o: Monster.cpp
	$(CC) $(CFLAGS) Monster.cpp 
   
Palico.o:Palico.cpp
	$(CC) $(CFLAGS) Palico.cpp 

Point.o:Point.cpp
	$(CC) $(CFLAGS) Point.cpp 

Monsterbook.o: Monsterbook.cpp
	$(CC) $(CFLAGS) Monsterbook.cpp

HunterBook.o: HunterBook.cpp
	$(CC) $(CFLAGS) HunterBook.cpp

PalicoBook.o: PalicoBook.cpp
	$(CC) $(CFLAGS) PalicoBook.cpp

bmplib.o: bmplib.cpp
	$(CC) $(CFLAGS) bmplib.cpp

runGame.o: runGame.cpp
	$(CC) $(CFLAGS) runGame.cpp

Champion.o: Champion.cpp
	$(CC) $(CFLAGS) Champion.cpp

GUI.o: GUI.cpp
	$(CC) $(CFLAGS) GUI.cpp

PA2_main.o: PA2_main.cpp -lpthread
	$(CC) $(CFLAGS) PA2_main.cpp -lpthread

clean: 
	rm -f *.o 
