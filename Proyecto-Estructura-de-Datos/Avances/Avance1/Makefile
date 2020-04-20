a.out: main.o proyecto.o
	gcc main.o proyecto.o
main.o: main.c
	gcc -c main.c
proyecto.o: proyecto.c
	gcc -c proyecto.c
run: a.out
	./a.out
clear:
	rm a.out main.o proyecto.o 