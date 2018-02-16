# Makefile de University
CFLAGS=-c -Wall

# Variables
CC = g++
EJECUTABLE = MAIN

# Programa Principal
all: node.h nodebin.h arbbin.h list.h tail.h stack.h main5.cpp
	$(CC) main5.cpp -o $(EJECUTABLE)


# Borrar los Archivos Objeto y el Ejecutable
clean:
	rm -rf *.o $(EJECUTABLE) 
