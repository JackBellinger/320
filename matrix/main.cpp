#include "Matrix.h"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

string time(string operation, Matrix<int>& a, Matrix<int>& b, int r, int c)
{
    // The "auto" type determines the correct type at compile-time
	Matrix<int>* timeMe;	
    	auto start = std::chrono::system_clock::now();
	if(operation == "+")
	{

    		timeMe = new Matrix<int>(r, c);
    		timeMe->add(a, b);
	}
	if(operation == "-")
	{
		timeMe = new Matrix<int>(r, c);
		timeMe->subtract(a, b);
	}
	if(operation == "*")
	{	
		timeMe = new Matrix<int>(r, c);
		timeMe->n3Multiply(a, b);
	}
	

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout << "finished " << operation << " ing " << r << " #long matrixs" << endl 
	 <<" at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " s" << endl;
	return timeMe->printMatrix();
}

int main()
{
	//I was getting invalid free/delete from c++ trying to deconstruct x and y before they were pointers
	Matrix<int>* x;// =  new Matrix<int>(size, size);
	Matrix<int>* y;// = new Matrix<int>(size, size);

	string fills[] = {"fill", "diagonal", "upper-triangle", "lower-triangle", "random"};
	int numFills = 4;

	try{//multiplication timing
		 
		for(int size = 2; size < 16; size*=2)
		{
			x =  new Matrix<int>(size, size);
			y = new Matrix<int>(size, size);

			for(int f = 0; f< numFills; f++){
				x->fillMatrix(fills[f], 4);
				y->fillMatrix(fills[f], 4);	
				cout << fills[f] << " matricies w/ size = " << size << endl;
				cout << time("*", *x, *y, size, size);
				cout << endl;
			}
		}
	}
	catch(string e)
	{	
		cout << "multiplication error" << e << endl;
	}
	try{//addition timing
		 
		for(int size = 2; size < 16; size*=2)
		{
			x =  new Matrix<int>(size, size);
			y = new Matrix<int>(size, size);

			for(int f = 0; f< numFills; f++){
				x->fillMatrix(fills[f], 4);
				y->fillMatrix(fills[f], 4);
				cout << fills[f] << " matricies w/ size = " << size << endl;
				cout << time("+", *x, *y, size, size);
				cout << endl;
			}
		}
	}
	catch(string e)
	{	
		cout << "addition error" << e << endl;
	}

	return 0;
}
