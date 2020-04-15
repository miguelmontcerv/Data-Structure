a.out: main.o lsdobles.o
	gcc main.o lsdobles.o
main.o: main.c
	gcc -c main.c
lsdobles.o: lsdobles.c
	gcc -c lsdobles.c
run: a.out
	./a.out
clear:
	rm a.out main.o lsdobles.o 