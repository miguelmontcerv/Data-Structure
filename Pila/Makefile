a.out: main.o pila.o
	gcc main.o pila.o
main.o: main.c
	gcc -c main.c
pila.o: pila.c
	gcc -c pila.c
run: a.out
	./a.out
clear:
	rm a.out main.o pila.o 
