all: bst timeBST clean

bst: BSTEngine.o BST.o 
	g++ -std=c++11 manualInstantiation.cpp -o bst -g

timeBST: timing.o BST.o
	g++ -std=c++11 timeInstantiation.cpp -I/usr/include/python2.7 -lpython2.7 -o timeBST -g 

timing.o: timing.cpp
	g++ -std=c++11 -c timing.cpp -g -I/usr/include/python2.7 -lpython2.7 
BST.o: BST.cpp
	g++ -std=c++11 -c BST.cpp -g
BSTEngine.o: BSTEngine.cpp
	g++ -std=c++11 -c BSTEngine.cpp -g
clean:
	rm -rf *o
