#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <string>
using namespace std;
template <class T>
class row
{
	private:
		T* data;
		size_t size;
	public:
		row(size_t);
		T& operator [] (size_t);
};

template <class T>
class Matrix
{
	//private:
	public:
		T** data;
		int numCols;
		int numRows;
	//public:
		Matrix(int, int);
		~Matrix();
		Matrix(Matrix&);
		T*& operator [] (int);
		void operator = ( Matrix);
		T at(int, int);
		Matrix operator *(  Matrix) ;
		Matrix operator +(Matrix);
		Matrix operator -(Matrix);
		Matrix* n3Multiply(Matrix&, Matrix&) ;		
		Matrix* strassenMultiply(Matrix&, Matrix&);
		Matrix* add(Matrix&,  Matrix&) ;
		Matrix* subtract(Matrix&, Matrix&) ;
		template <class D>
		friend 	ostream& operator <<(ostream&, Matrix<D>&);
		Matrix* pad();
		void fillMatrix(string, T);
		string printMatrix() ;

};
#endif
