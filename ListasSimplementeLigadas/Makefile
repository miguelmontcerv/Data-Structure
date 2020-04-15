a.out: main.o lssligadas.o
	gcc main.o lssligadas.o
main.o: main.c
	gcc -c main.c
lssligadas.o: lssligadas.c
	gcc -c lssligadas.c
run: a.out
	./a.out
clear:
	rm a.out main.o lssligadas.o 