all: main.o bd.o
	gcc main.o bd.o

main.o: main.c
	gcc -c main.c

bd.o: bd.c
	gcc -c bd.c

clean:
	rm *.o
	rm a.out