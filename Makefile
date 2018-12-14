all: prog
prog: funcao.o main.o
	gcc -o prog funcao.o main.o
lista.o: funcao.c
	gcc -o prog.o -c funcao.c
main.o: main.c funcao.h
	gcc -o main.o -c main.c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf all