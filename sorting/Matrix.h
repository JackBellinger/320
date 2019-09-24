#ifndef MATRIX_H
#define MATRIX_H

#include <stdio>
using namespace std;

template <Class T>
class Matrix
{
	private:
		T** data;
		size_t numCols;
		size_t numRows;
	public:
		Matrix(size_t, size_t);
		~Matrix();
		T*&operator[](size_t);
		
		
}
