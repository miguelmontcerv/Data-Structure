a.out: main.o lscdoble.o
	gcc main.o lscdoble.o
main.o: main.c
	gcc -c main.c
lscdoble.o: lscdoble.c
	gcc -c lscdoble.c
run: a.out
	./a.out
clear:
	rm a.out main.o lscdoble.o 
