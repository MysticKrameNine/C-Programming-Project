list.h= ~/Bureau/projectc/projectcV/include/list.h
list.c= ~/Bureau/projectc/projectcV/source/list.c
main:main.o list.o
	gcc list.o main.o -o main

main.o:$(list.c) $(list.h)
	gcc -c main.c -I../include ../source/list.c

list.o:main.c $(list.h)
	gcc -c main.c -I../include 
	