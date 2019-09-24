all: sort clean

sort: main.o Sort.o
	g++ -std=c++11 -o sort instantiation.cpp -g
main.o: main.cpp
	g++ -std=c++11 -c main.cpp -g
Sort.o: Sort.cpp
	g++ -std=c++11 -c Sort.cpp -g

clean:
	rm -rf *o


