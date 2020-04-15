a.out: main.o abb.o
	gcc main.o abb.o
main.o: main.c
	gcc -c main.c
abb.o: abb.c
	gcc -c abb.c
run: a.out
	./a.out
clear:
	rm a.out main.o abb.o 
