all: spellchecker clean

spellchecker: Main.o RBTree.o HashTable.o Word.o
	g++ -std=c++11 mainInstantiation.cpp -o spellchecker -g 

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp -g

HashTable.o: HashTable.cpp
	g++ -std=c++11 -c HashTable.cpp -g 

RBTree.o: RBTree.cpp
	g++ -std=c++11 -c RBTree.cpp -g

Word.o:
	g++ -std=c++11 -c Word.cpp -g

clean:
	rm -rf *o
