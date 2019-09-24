 
#include "Sort.h"
#include <iostream>
#include <array>
#include <cstddef>//size_t
#include <cstdlib>//rand

void Sort::swap(int& A, int& B)
{//swaps two variables
	int c = A;
	A = B;
	B = c;
}
size_t Sort::insertion(int* array, double length)
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

size_t Sort::selection(int* array, double length)
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


size_t Sort::bubble(int* array, double length)
{
	int numSwapped = 0;
	bool swapped = true;
	//keeps bubbling until it goes through the whole array and doesn't swap anything
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

size_t* Sort::partitionQS(int* array, size_t start, size_t end)
{//returns the pivot location and the number of swaps in an array 
	size_t pivotIndex = start;//getPivot(array, start, end);
	size_t pivotValue = array[pivotIndex];
	size_t i = start;
	size_t numSwaps = 0;
	
	
	//swap things less than the pivot value to the lef until it reaches the end
	for(size_t j = start+1; j < end; j++)
		if(array[j] <= pivotValue)
		{
			swap(array[j], array[++i]);//increments before it swaps			
			numSwaps++;
		}
	swap(array[pivotIndex], array[i]);
			//*make sure to delete*
	size_t* ret = new size_t[2];
	//return both the pivot position and the number of swaps
	ret[0] = i;
	ret[1] = numSwaps;
	return ret;

}


size_t Sort::quick(int* array, size_t start, size_t end)
{
	size_t numSwaps = 0;
	if(start < end)
	{
		size_t* both = partitionQS(array, start, end);
		size_t p = both[0];
		numSwaps += both[1];
		delete [] both;//removes the array from the heap
		//sort the left side and then the right
		numSwaps += quick(array, start, p);
		numSwaps += quick(array, p+1, end);
	}
	return numSwaps;
}

size_t* Sort::randomizedPartition(int* array, size_t start, size_t end)
{
	//if(start < end) handled by randomizedQS b/c the return value is easier
	size_t pivotIndex = (rand() % (end - start)) + start;
	swap(array[start], array[pivotIndex]);
	return partitionQS(array, start, end);
}
size_t Sort::randomizedQuick(int* array, size_t start, size_t end)
{
	size_t numSwaps = 0;
	if(start < end)
	{
		size_t* both = randomizedPartition(array, start, end);
		size_t p = both[0];
		numSwaps += both[1];
		delete[] both;
		
		numSwaps += randomizedQuick(array, start, p);
		numSwaps += randomizedQuick(array, p+1, end);
	}
	return numSwaps;
}
// A function to merge the two half into a sorted data.
size_t Sort::mergeSub(int *A, size_t start, size_t end, size_t mid)
{
	// We have start to mid and mid+1 to end already sorted.
	
	size_t i, j, k, temp[end-start+1];
	i = start;
	//i counts through the left subarray
	k = 0;
	//k counts through the temp array
	j = mid + 1;
 	//j is the right subarray
	// Merge the two parts into temp[].
	while (i <= mid && j <= end)
	{
		if (A[i] < A[j])
		{
			temp[k] = A[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = A[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from the left subarray into temp[].
	while (i <= mid)
	{
		temp[k] = A[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from the right subarray into temp[].
	while (j <= end)
	{
		temp[k] = A[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = start; i <= end; i++)
		A[i] = temp[i-start];
}
 
size_t Sort::merge(int *A, size_t start, size_t end)
{
	size_t mid;
	if (start < end)
	{
		mid=(start+end)/2;
		// Split the data into two half.
		merge(A, start, mid);
		merge(A, mid+1, end);
 
		// Merge them to get sorted output.
		mergeSub(A, start, end, mid);
	}
}
