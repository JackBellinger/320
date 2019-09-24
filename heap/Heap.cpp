#include "Heap.h"
#include "Student.h"
#include <cmath>

template <class T>
Heap<T>::Heap(int s)
{
	size = s;
	data = new T[size];
}

template <class T>
void Heap<T>::insert(T newData)
{
	int i = size;
	while(i > 0 && data[parent(i)] < newData)
	{
		data[i] = data[parent(i)];
		i = parent(i);
	}
	data[i] = newData;
	size++;
}
template <class T>
void Heap<T>::max()
{
	cout << " Max: " << data[0];
}
template <class T>
T Heap<T>::extractMax()
{
	if(size < 1)
	{
		cout << "error: heap underflow";
		return data[0];	
	}	
	else
	{
		T max = data[0];
		data[0] = data[size - 1];
		size--;
		heapify(0);
		return max;
	}
}
template <class T>
void Heap<T>::buildHeap(T* A, int s)
{
	size = s;
	for(int i = (size/2)-1; i >= 0; i--)  //start at the last internal node and heapify - basically just heapsort the new array
		heapify(i);
	cout << endl;
}
template <class T>
void Heap<T>::heapify(int i)
{
	int L = leftChild(i);
	int R = rightChild(i);
	int largest = i;
	if(i >= size)
		return;
	//cout << data[i];
	//cout << data[L];
	if( L < size && data[i] < data[L])
		largest = L;
	else
		largest = i;
	if( R < size && data[largest] < data[R])
		largest = R;

	if(largest != i)
	{
		swap(i, largest);
		heapify(largest);
	} 
}
template <class T>
int Heap<T>::leftChild(int i)
{
	return (2*i+ 1);
}
template <class T>
int Heap<T>::rightChild(int i)
{
	return 2*i+2;
}
template <class T>
int Heap<T>::parent(int i)
{
	if(i%2 == 0)
		return (i-1)/2;
	else
		return i/2;
}
template <class T>
void Heap<T>::swap(int x, int y)
{
	T temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}
bool isPow2(int x)
{
	return x > 0 && !(x & (x-1));
}
template <class T>
void Heap<T>::printHeap()
{
	//int height = log2(size);
	int nextEndl = 1;
	int offset = 2;
	for(int i = 0; i < size; i++)
	{
		if(i == nextEndl)
		{//if the main loop gets to an element that should be on a new line, cout endl
			cout << endl;
			nextEndl *= 2;
		}

		cout << data[i];
		
		//used to dynamically set the space between the elements
		for(int o = 0; o < offset; o++)
			cout << " ";
	}
		cout << endl << endl;
}

template <class T>
void Heap<T>::heapSort(T* array, int size)
{
	buildHeap(array, size);
	for(int i = 0; i < size; i++)
		array[i] = extractMax();
}

template <class T>
T Heap<T>::operator [](int i)
{
	return data[i];
}
