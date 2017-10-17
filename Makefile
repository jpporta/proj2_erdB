### Makefile ###

all: prog clean run rmpoper

prog: projetoGrafo.o funcoes.o loadBancoDeDados.o
	gcc -Wall -o prog projetoGrafo.o funcoes.o loadBancoDeDados.o -lm

funcoes.o: funcoes.c
	gcc -c funcoes.c

loadBancoDeDados.o: loadBancoDeDados.c
	gcc -c loadBancoDeDados.c

projetoGrafo.o: projetoGrafo.c
	gcc -c projetoGrafo.c

clean:
	rm -rf  *.o

rmpoper: clean
	rm -rf prog

run: prog clean
	./prog
