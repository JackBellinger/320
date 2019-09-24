#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap
{
public:
	T* data;
	int size;
	
	int leftChild(int);
	int rightChild(int);
	int parent(int);
	void swap(int, int);
	

	Heap(int = 100);
	
	void buildHeap(T*, int);
	void heapify(int);
	void max();
	T extractMax();
	void insert(T);
	void insert();
	void printHeap();
	void heapSort(T*, int);
	T operator [](int);

};


#endif
