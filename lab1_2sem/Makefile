all: main.o bd.o
	g++ main.o bd.o

main.o: main.cpp
	g++ -c main.cpp

bd.o: bd.cpp
	g++ -c bd.cpp

clean:
	rm *.o
	rm a.out