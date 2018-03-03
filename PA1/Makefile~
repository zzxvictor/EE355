# Makefile for PA1
# variables 
CC = g++

CFLAGS = -c -Wall

all: PA1
	./PA1
PA1: run.o Hunter.o Monster.o Palico.o main.o
	$(CC) run.o Hunter.o Monster.o Palico.o main.o -o PA1

Hunter.o: Hunter.cpp
	$(CC) $(CFLAGS) Hunter.cpp 
   
Monster.o: Monster.cpp
	$(CC) $(CFLAGS) Monster.cpp 
   
Palico.o:Palico.cpp
	$(CC) $(CFLAGS) Palico.cpp 
   
run.o: run.cpp
	$(CC) $(CFLAGS) run.cpp 

main.o: 
	$(CC) $(CFLAGS) main.cpp
clean: 
	rm -rf *o 
