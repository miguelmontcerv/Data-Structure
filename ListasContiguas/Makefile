a.out: main.o contiguas.o
	gcc main.o contiguas.o
main.o: main.c
	gcc -c main.c
contiguas.o: contiguas.c
	gcc -c contiguas.c
run: a.out
	./a.out
clear:
	rm a.out main.o contiguas.o 