GCC=gcc -Wall -ansi --pedantic

	
input.o: input.c input.h
	gcc -c input.c
main.o: main.c input.h pictures.h map.h
	gcc -c main.c
map.o: map.c map.h
	gcc -c map.c
pictures.o: pictures.c pictures.h map.h
	gcc -c pictures.c


all: main.c input.c input.h pictures.c pictures.h map.c map.h
	$(GCC) main.c input.c pictures.c map.c

al: main.c input.c input.h pictures.c pictures.h map.c map.h
	gcc  main.c input.c pictures.c map.c

alld: main.c input.c input.h pictures.c pictures.h map.c map.h
	$(GCC) main.c input.c pictures.c map.c -DDEBUG

ald: main.c input.c input.h pictures.c pictures.h map.c map.h
	gcc  main.c input.c pictures.c map.c -DDEBUG


clean:
	rm *.o *.out

