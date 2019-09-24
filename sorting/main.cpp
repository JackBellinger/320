 
#include "Sort.h"
#include "Heap.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <cstddef>
using namespace std;

void generateForwardSorted(int* array, double length)
{
	
	for(int i = 0; i < length; i++)
	{
		array[i] = i;
	}
}

void generateBackwardSorted(int* array, double length)
{
	
	for(int i = 0; i < length; i++)
	{
		array[i] = length - 1 - i;
	}
}
void generateRandomSorted(int* array, double length)
{
	generateForwardSorted(array, length);
	for(int i = 0; i < length; i++)//length*length*length; i++)
	{
		size_t r = rand() % (int)length;
		size_t r2 = rand() % (int)length;
		swap(array[r], array[r2]);
	}	
}
void printArray(int* array, double length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
bool validateAscendingSort(int* array, double length)
{//checks if every element is greater than the previous
	for(int i = 1; i < length; i++)
		if(array[i - 1] > array[i])
		{	
			cout << array[i-1] << " > " << array[i] << endl;
			return false;
		}
	return true;
}
double timeBasicSorts(size_t (*sortingAlgo)(int*, double), int* array, double length)
{
    // The "auto" type determines the correct type at compile-time
    auto startT = std::chrono::system_clock::now();
    
    size_t swaps = sortingAlgo(array, length);
    
    auto endT = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(endT);
    
    //cout << "finished at " << std::ctime(&end_time) 
    //     << "elapsed time: " << time << " s"
    //     << "\nNumber of swaps: " << swaps << "\n";
   //double checks that the array is sorted correctly
   if(validateAscendingSort(array, length))
	cout << "Array is Sorted Correctly" << endl;
    else
    	cout << "Array is not Sorted Correctly" << endl;
    return time;
}

double timeRecursiveSorts( size_t (*sort) (int*, size_t, size_t), int* array, size_t start, size_t end)
{
	// The "auto" type determines the correct type at compile-time
    auto startT = std::chrono::system_clock::now();
    
    size_t swaps = sort(array, start, end);
    
    auto endT = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(endT);
    
    /*cout << "finished at " << std::ctime(&end_time) 
         << "elapsed time: " << time << " s"
         << "\nNumber of swaps: " << swaps << "\n";
   //double checks that the array is sorted correctly
   if(validateAscendingSort(array, end))
	cout << "Array is Sorted Correctly" << endl;
    else
    	cout << "Array is not Sorted Correctly" << endl;
    */
    return time;
}
double timeHeapSort(int* array, int size)
{
	Heap<int> heap(size);
	// The "auto" type determines the correct type at compile-time
    auto startT = std::chrono::system_clock::now();
    heap.heapSort(array, size);
    //size_t swaps = quickSort(array, start, end);
    
    auto endT = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = endT-startT;
	double time = elapsed_seconds.count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(endT);
    
    /*cout << "finished at " << std::ctime(&end_time) 
         << "elapsed time: " << time << " s\n";
         << "\nNumber of swaps: " << swaps << "\n";
   //double checks that the array is sorted correctly
   if(validateAscendingSort(array, size))
	cout << "Array is Sorted Correctly" << endl;
    else
    	cout << "Array is not Sorted Correctly" << endl;
    */
    return time;
}

int lab1()
{
	int numGenerators = 3;
	void(*generators[3])(int*, double);
	generators[0] = generateForwardSorted;
	generators[1] = generateBackwardSorted;
	generators[2] = generateRandomSorted;
	string generatorNames[3] = {"Ascending Order", "Descending order", "Random order" }; 

	int numSorters = 3;
	size_t(*sorters[numSorters])(int*, double);
	sorters[0] = Sort::bubble;
	sorters[1] = Sort::insertion;
	sorters[2] = Sort::selection;
	string sorterNames[3] = {"Bubble Sort", "Insertion Sort", "Selection Sort" }; 

	//loop through all the different sizes, generated array types, and sorting algorithms and test the runtime and # swaps of each
	for(int SIZE = 10; SIZE <= 1000000; SIZE *= 10)
	{	
		int array[SIZE];
		for(int g = 0; g < numGenerators; g++)
			//for(int x = 0; x < 10; x++)used for more samples of random arrays
			for(int s = 0; s < numSorters; s++)
			{
				generators[g](array, SIZE); 
				cout << endl << endl
				<< "Array with " << SIZE
				<< " elements is in "
				<< generatorNames[g] <<
				" and will be sorted by "
				<< sorterNames[s] << endl; 
				
				timeBasicSorts(sorters[s], array, SIZE);
			}
		//delete [] array;
		
	}

}

int lab2()
{
	int numGenerators = 3;
	void(*generators[3])(int*, double);
	generators[0] = generateForwardSorted;
	generators[1] = generateBackwardSorted;
	generators[2] = generateRandomSorted;
	string generatorNames[3] = {"Ascending Order", "Descending order", "Random order" }; 
	
	int numSorters = 2;
	size_t(*sorters[numSorters])(int*, size_t, size_t);
	sorters[0] = Sort::quick;
	sorters[1] = Sort::randomizedQuick;
	sorters[2] = Sort::merge;
	string sorterNames[2] = {"Quick Sort", "Merge Sort"}; 
	for(int SIZE = 10; SIZE <= 1000000; SIZE *= 10)
	{	
		int array[SIZE];
		for(int g = 1; g < numGenerators; g++){
			//for(int x = 0; x < 10; x++)//used for more samples of random arrays
			for(int s = 0; s < numSorters; s++)
			{	
				generators[g](array, SIZE); 	
				cout << endl << endl << "Array with " << SIZE 
				<< " elements is in " << generatorNames[g] << 
				" and will be sorted by " << sorterNames[s]<<endl; 
				timeRecursiveSorts(sorters[s] , array, 0, SIZE);
				//printArray(array, SIZE);
			}
		}
	}
	return 1;
}
int lab6()
{
	int numGenerators = 3;
	void(*generators[3])(int*, double);
	generators[0] = generateForwardSorted;
	generators[1] = generateBackwardSorted;
	generators[2] = generateRandomSorted;
	string generatorNames[3] = {"Ascending Order", "Descending order", "Random order" }; 
	
	int numSorters = 3;
	size_t(*sorters[numSorters])(int*, size_t, size_t);
	sorters[0] = Sort::quick;
	sorters[1] = Sort::randomizedQuick;
	sorters[2] = Sort::merge;
	string sorterNames[3] = {"Quick Sort", "Randomized Quick Sort", "Merge Sort"};
	for(int s = 0; s < 3; s++)
	{
		int oldSize = 0;
		for(int SIZE = 10000; SIZE <= 1000000; SIZE += 50000)
		{
			int array[SIZE];
			double sumDeltaTime = 0;
			double numDeltaTimes = 0;
			double oldTime = 0;
			for(int x = 0; x < 20; x++)
			{
				int g = 2;
				//for(int g = 2; g < numGenerators; g++)
				{	
					generators[g](array, SIZE); 	

					//cout << endl << endl << "Array with " << SIZE 
					//<< " elements is in " << generatorNames[g] << 
					//" and will be sorted by " << sorterNames[s]<<endl;			
					double time = timeRecursiveSorts(sorters[s] , array, 0, SIZE);
					sumDeltaTime += time - oldTime;
					numDeltaTimes++;
					oldTime = time;
					//printArray(array, SIZE);
				}//generators loop
			}//samples loop
			double averageDeltaTime = sumDeltaTime / numDeltaTimes;
			int deltaSize = SIZE - oldSize;
			double timePerElement = averageDeltaTime / deltaSize;
			cout << "For " << sorterNames[s] << " w/ size from " << oldSize << "->" << SIZE << "\n The average delta time per delta element = " << timePerElement << endl << endl;
			oldSize = SIZE;
		}//size loop
	}//sorters loop
		//time heapsort
		double sumTime = 0;
		double numTimes = 0;
		int oldSize = 0;
		for(int SIZE = 10000; SIZE <= 1000000; SIZE += 50000)
		{
			int array[SIZE];
			double sumDeltaTime = 0;
			double numDeltaTimes = 0;
			double oldTime = 0;
			for(int x = 0; x < 20; x++)
			{
				
				for(int g = 2; g < numGenerators; g++)
				{	
					generators[g](array, SIZE); 	
					//cout << endl << endl << "Array with " << SIZE 
					//<< " elements is in " << generatorNames[g] << 
					//" and will be sorted by Heap Sort" <<endl; 
					double time = timeHeapSort(array, SIZE); 
					sumDeltaTime += time - oldTime;
					numDeltaTimes++;
					oldTime = time;
					//printArray(array, SIZE);
				}//generators loop
			}//samples loop
			double averageDeltaTime = sumDeltaTime / numDeltaTimes;
			int deltaSize = SIZE - oldSize;
			double timePerElement = averageDeltaTime / deltaSize;
			cout <<  "For HeapSort w/ size from " << oldSize << "->" << SIZE << "\n The average delta time per delta element" << " : " << timePerElement << endl << endl;
			oldSize = SIZE;
		}
	return 1;
}
int main()
{
	lab6();
}

