 
#ifndef SORT_H
#define SORT_H
#include <cstddef>
using namespace std;

class Sort 
{
public:
	
	static void swap(int&, int&);	
	static size_t bubble(int*, double);
	static size_t selection(int*, double);
	static size_t insertion(int*, double);
	static size_t quick(int*, size_t, size_t);
	static size_t* partitionQS(int*, size_t, size_t);
	static size_t randomizedQuick(int*, size_t, size_t);
	static size_t* randomizedPartition(int*, size_t, size_t);
	static size_t mergeSub(int*, size_t, size_t, size_t);
        static size_t merge(int*, size_t, size_t);	
};

#endif
