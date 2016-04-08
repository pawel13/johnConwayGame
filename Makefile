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
	$(GCC) main.c input.c pictures.c map.c -lpng -lm -lz

al: main.c input.c input.h pictures.c pictures.h map.c map.h
	gcc  main.c input.c pictures.c map.c -lpng -lm -lz

alld: main.c input.c input.h pictures.c pictures.h map.c map.h
	$(GCC) main.c input.c pictures.c map.c -DDEBUG -lpng -lm -lz

ald: main.c input.c input.h pictures.c pictures.h map.c map.h
	gcc  main.c input.c pictures.c map.c -DDEBUG -lpng -lm -lz


alasd: main.c input.c input.h pictures.c pictures.h map.c map.h
	gcc -c main.c input.c pictures.c map.c -DDEBUG -lpng -lm -lz
	objdump -d main.o input.o pictures.o map.o

run: a.out 
	./a.out -i test.png -o testResult.png
	
example: shortExample.c
	gcc shortExample.c -lpng -lm -lz

exrun: a.out
	./a.out test.png testRandom.png

clean:
	rm *.o *.out

