all: Sorting clean

Sorting: Sort.o Main.o
	g++ -std=c++11 -o a.out Sort.o Main.o
Sort.o: Sort.cpp
	g++ -std=c++11 -c Sort.cpp
Main.o:
	g++ -std=c++11 -c Main.cpp
clean:
	rm -rf *o
