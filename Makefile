all: prog1

prog1: main.o
	g++ -g main.o -o prog1

main.o: main.cpp prog1.h
	g++ -c -g main.cpp

clean:
	rm -rf *.o
