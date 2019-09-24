all: heap clean

heap: instantiation.cpp Heap.o Student.o Main.o
	g++ -std=c++11 instantiation.cpp -o heap -g
Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp -g
Heap.o: Heap.cpp
	g++ -std=c++11 -c Heap.cpp -g
Student.o: Student.cpp
	g++ -std=c++11 -c Student.cpp -g
clean:
	rm -rf *o
