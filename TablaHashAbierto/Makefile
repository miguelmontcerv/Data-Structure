 a.out: main.o hash.o
	gcc main.o hash.o
main.o: main.c
	gcc -c main.c
hash.o: hash.c
	gcc -c hash.c
run: a.out
	./a.out
clear:
	rm a.out main.o hash.o