#include "Matrix.h"
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <string>
using namespace std;

//main  ructor
template <class T>
Matrix<T>::Matrix(int r, int c)
{
	if(r <= 0 || c <= 0)
		cout << "can't make an array with negative/zero number of rows/columns" << endl;
	else
	{
		numRows = r;
		numCols = c;
		data = new T*[numRows]; //creat the array that stores the rows
		for(int i = 0; i < numRows; i++)
			data[i] = new T[numCols]; //create each row, which is num columns long
	}
}

template <class T>
Matrix<T>::~Matrix()
{
	for( int i = 0; i < numCols; i++)
		delete[] data[i]; //delete each row
	delete[] data; //delete the array of rows
}

//copy  ructor
template <class T>
Matrix<T>::Matrix(Matrix& copy)
{
	if(copy.numRows <= 0 || copy.numCols <= 0)
		cout << "can't make an array with negative/zero number of "
			<< "rows/columns" << endl;
	else
	{
		data = new T*[copy.numRows]; //creat the array that stores the rows
		for(int i = 0; i < copy.numRows; i++)
			data[i] = new T[copy.numCols]; //create each row, which is num columns long
	}
	for(int i = 0; i < copy.numRows; i++)
		for (int j = 0; j < copy.numCols; j++)
			data[i][j] = copy.data[i][j];
}

template <class T>
void Matrix<T>::operator =( Matrix rhs)
{
	numRows = rhs.numRows;
	numCols = rhs.numCols;
	data = rhs.data;
}
template <class T>
ostream& operator <<(ostream& os, Matrix<T>& rhs)
{
	return os <<rhs.printMatrix();
}

template <class T>
Matrix<T> Matrix<T>::operator *(  Matrix<T> rhs)
{
	return *n3Multiply(*this, rhs);
}

template <class T>
Matrix<T> Matrix<T>::operator +(  Matrix<T> rhs)
{
	return *add(*this, rhs);
}

template <class T>
Matrix<T> Matrix<T>::operator -(  Matrix<T> rhs)
{
	return *subtract(*this, rhs);
}
template <class T>
T*& Matrix<T>::operator [](int row)
{
	//change the index to size_t?
	return data[row];
}
template <class T>
T Matrix<T>::at(int i, int j)
{
	return data[i][j];
}
template <class T>
Matrix<T>* Matrix<T>::n3Multiply(Matrix<T>& lhs,  Matrix<T>& rhs)
{
	//if(lhs!=0 && rhs!=0)
	if(lhs.numCols != rhs.numRows)
		throw "left hand side's number of columns != right hand side's number of rows";
	//Matrix<T> output = Matrix(numRows, rhs.numCols);
	Matrix<T>* output = new Matrix(lhs.numRows, rhs.numCols);
	for(int i = 0; i < lhs.numRows; i++)
		for(int j = 0; j < rhs.numCols; j++)
			for(int k = 0; k < rhs.numCols; k++)
				output->data[i][j] = lhs[i][j] * rhs[k][j]; 
	this->data = output->data;
	return output;
}

template <class T>
Matrix<T>* Matrix<T>::strassenMultiply(Matrix<T>& lhs, Matrix<T>& rhs)
{
	if(lhs.numRows <= 4 && rhs.numCols <= 4)
		return n3Multiply(lhs, rhs);
	else
	{
		Matrix<T>* output = new Matrix<T>(lhs.numRows/2, lhs.numCols/2);
	}
}

template <class T>
Matrix<T>* Matrix<T>::pad()
{
	int newSize = 2;
	while(newSize < numRows)
	{
		newSize*=2;
	}
}

template <class T>
Matrix<T>* Matrix<T>::add(Matrix<T>& lhs,  Matrix<T>& rhs)
{
	if(lhs.numRows != rhs.numRows || lhs.numCols != rhs.numCols)
		throw "the rows and columns don't match";
	Matrix<T>* output = new Matrix(lhs.numRows, rhs.numCols);
	//Matrix<T> output = Matrix(numRows, numCols);
	for(int i = 0; i < lhs.numRows; i++)
		for(int j = 0; j < rhs.numCols; j++)
			output->data[i][j] = lhs[i][j] + rhs[i][j];
	this->data = output->data;
	return output;
}

template <class T>
Matrix<T>* Matrix<T>::subtract(Matrix<T>& lhs,  Matrix<T>& rhs)
{
	if(lhs.numRows != rhs.numRows || lhs.numCols != rhs.numCols)
		throw "the rows and columns don't match";
	//Matrix<T> output = Matrix(numRows, numCols);
	Matrix<T>* output = new Matrix(lhs.numRows, lhs.numCols);
	for(int i = 0; i < lhs.numRows; i++)
		for(int j = 0; j < rhs.numCols; j++)
			output->data[i][j] = lhs[i][j] - rhs[i][j];
	this->data = output->data;
	return output;
}
template <class T>
void Matrix<T>::fillMatrix(string type, T value)
{
	
	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
		{
			if(type == "full")
				data[i][j] = value;

			if(type == "diagonal")
			{
				if(i == j)
					data[i][j] = value;
				else
					data[i][j] = 0;
			}
			if(type == "upper-triangle")
			{
				if(j > i)
					data[i][j] = value;
				else
					data[i][j] = 0;
			}
			if(type == "lower-triangle")
			{
				if(i > j)
					data[i][j] = value;
				else
					data[i][j] = 0;
			}
			if(type == "random")
				data[i][j] = (rand() % value) + 1;
		}
}
template <class T>
string Matrix<T>::printMatrix()
{
	string out = "";
	for(int i = 0; i < numRows; i++)
	{
		out += "| ";
		for(int j = 0; j < numCols; j++)
			out += to_string(data[i][j]) + " ";
		out += "|\n";
	}
	return out;
}



