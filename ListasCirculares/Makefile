a.out: main.o lscirculares.o
	gcc main.o lscirculares.o
main.o: main.c
	gcc -c main.c
lscirculares.o: lscirculares.c
	gcc -c lscirculares.c
run: a.out
	./a.out
clear:
	rm a.out main.o lscirculares.o 