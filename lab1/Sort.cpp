 
#include "Sort.h"
#include <iostream>
void Sort::swap(int& A, int& B)
{
	int c = A;
	A = B;
	B = c;
}

int Sort::insertion(int* array, int length)
{
	int numSwapped = 0;
	bool swapped = true;
	for(int i = 0; i < length; i++)
	{
		if(!swapped)
			break;
		bool swapped = false;
		for(int j = i; j > 0; j--)
		{
			if(array[j] < array[j-1])
			{
				swap(array[j], array[j -1]);
				numSwapped++;
				swapped = true;
			}
		}
	}
	
return numSwapped;
}

int Sort::selection(int* array, int length)
{
	int numSwapped = 0;

	for(int k = 0; k < length - 1; k++)
	{
		int minIndex = k;
		for(int i = k + 1; i < length; i++)
		{
			if(array[i] < array[minIndex])
				minIndex = i;
		}
		if(minIndex != k){
			swap(array[minIndex],  array[k]);
			//cout << minIndex <<" swap with " << k << endl;
			numSwapped++;
		}
	}
return numSwapped;
}

int Sort::bubble(int* array, int length)
{
	int numSwapped = 0;
	bool swapped = true;
	while(swapped)
	{
		swapped = false;
		for(int i = 0; i < length - 1; i++)
		{
			if(array[i] > array[i+1])
			{
				swap(array[i], array[i+1]);
				swapped = true;
				numSwapped++;
			}
			
		}
	}
	return numSwapped;
}
