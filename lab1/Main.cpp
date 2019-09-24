 
#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

void generateForwardSorted(int* array, int length)
{
	
	for(int i = 0; i < length; i++)
	{
		array[i] = i;
	}
}

void generateBackwardSorted(int* array, int length)
{
	
	for(int i = 0; i < length; i++)
	{
		array[i] = length - 1 - i;
	}
}
void generateRandomArray(int* array, int length)
{
	for(int i = 0; i < length; i++)
	{
		array[i] = rand();
	}	
}
void printArray(int* array, int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
bool validateAscendingSort(int* array, int length)
{
	for(int i = 1; i < length; i++)
		if(array[i - 1] > array[i])
		       return false;
	return true;
}
int timeSortingFunction(int (*sortingAlgo)(int*, int), int* array, int length)
{
    // The "auto" type determines the correct type at compile-time
    auto start = std::chrono::system_clock::now();
    
    int swaps = sortingAlgo(array, length);
    
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "finished at " << std::ctime(&end_time) 
         << "elapsed time: " << elapsed_seconds.count() << " s"
         << "\nNumber of swaps: " << swaps << "\n";
   if(validateAscendingSort(array, length))
	cout << "Array is Sorted Correctly";
    else
    	cout << "Array is not Sorted Correctly";
    return swaps;
}
int main()
{
	int numGenerators = 3;
	void(*generators[3])(int*, int);
	generators[0] = generateForwardSorted;
	generators[1] = generateBackwardSorted;
	generators[2] = generateRandomArray;
	string generatorNames[3] = {"Ascending Order", "Descending order", "Random order" }; 
	int numSorters = 3;
	int(*sorters[numSorters])(int*, int);
	sorters[0] = Sort::bubble;
	sorters[1] = Sort::insertion;
	sorters[2] = Sort::selection;

	string sorterNames[3] = {"Bubble Sort", "Insertion Sort", "Selection Sort" }; 

	
	for(int SIZE = 10; SIZE < 10000000; SIZE *= SIZE)
	{	
		int array[SIZE];
		for(int g = 0; g < numGenerators; g++)
			for(int s = 0; s < numSorters; s++)
			{
				generators[g](array, SIZE); 
				cout << endl << endl << "Array with " << SIZE << " elements is in " << generatorNames[g] << " and will be sorted by " << sorterNames[s] << endl; 
				timeSortingFunction(sorters[s] , array, SIZE);
			}
		
	}

}

