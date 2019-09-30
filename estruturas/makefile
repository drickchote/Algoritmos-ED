#Makefile da fila

all: compila

compila: main.o fila.o
	gcc -o fila main.o fila.o

main.o: main.c
	gcc -c main.c -Wall

fila.o: fila.c fila.h
	gcc -c fila.c -Wall

clear: 
	rm -f *.o fila

