a.out: main.o avl.o
	gcc main.o avl.o
main.o: main.c
	gcc -c main.c
avl.o: avl.c
	gcc -c avl.c
run: a.out
	./a.out
clear:
	rm a.out main.o avl.o 