# Makefile for PA2
# variables 
CC = g++

CFLAGS = -c -Wall

all: PA2
	./PA2
PA2: run.o Item.o Point.o Hunter.o Monster.o Palico.o main.o
	$(CC) run.o Item.o Point.o Hunter.o Monster.o Palico.o main.o -o PA2

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

run.o: run.cpp
	$(CC) $(CFLAGS) run.cpp 

main.o: 
	$(CC) $(CFLAGS) main.cpp


clean: 
	rm -rf *o 
