#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

string time(string operation, Matrix<int>& a, Matrix<int>& b, int r, int c)
{
    // The "auto" type determines the correct type at compile-time
	Matrix<int> timeMe;	
    	auto start = std::chrono::system_clock::now();
	if(operation == "+")
    		timeMe = a + b;
	
	if(operation == "-")
		timeMe = a - b;
	
	if(operation == "*")
		timeMe = a * b;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout << "finished " << operation << " ing " << r << " #long matrixs" << endl 
	 <<" at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " s" << endl;
	return timeMe.printMatrix();
}

int main1()
{
	//I was getting invalid free/delete from c++ trying to deconstruct x and y before they were pointers
	Matrix<int> x;// =  new Matrix<int>(size, size);
	Matrix<int> y;// = new Matrix<int>(size, size);
	string fills[] = {"fill", "diagonal", "upper-triangle", "lower-triangle", "random"};
	int numFills = 4;

	try{//multiplication timing
		 
		for(int size = 2; size < 16; size*=2)
		{
			x = Matrix<int>(size, size);
			y = Matrix<int>(size, size);

			for(int f = 0; f< numFills; f++){
				x.fillMatrix(fills[f], 4);
				y.fillMatrix(fills[f], 4);	
				cout << fills[f] << " matricies w/ size = " << size << endl;
				cout << time("*", x, y, size, size);
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
			x = Matrix<int>(size, size);
			y = Matrix<int>(size, size);

			for(int f = 0; f< numFills; f++){
				x.fillMatrix(fills[f], 4);
				y.fillMatrix(fills[f], 4);
				cout << fills[f] << " matricies w/ size = " << size << endl;
				cout << time("+", x, y, size, size);
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
Matrix<double> readFile(char* fileName)
{
	string line;
	int numLines = 0;
	Matrix<double> pointsMatrix;
	ifstream pointsFile (fileName);
	if(pointsFile.is_open()){
		while(getline(pointsFile, line))
			numLines++;
		pointsFile.clear();
		pointsFile.seekg(0, ios::beg);
		cout << numLines;
		pointsMatrix = Matrix<double>(numLines, 2);
		bool isX = true;
		double temp = 0;
		int i = 0;
		while(pointsFile >> temp && i < numLines)
		{
			if(isX)
			{
				pointsMatrix[i][0] = temp;
				isX = false;
			}
			else
			{
				pointsMatrix[i][1] = temp;
				isX = true;
				i++;
			}
		}
	pointsFile.close();
	}
	return pointsMatrix;
			
}
int main(int argc, char** argv)
{
	if(argc != 2)
	{
		cout << "this program only takes 1 parameter";
		return 0;
	}
	Matrix<double> x = Matrix<double>(3, 3);
	x[0][0] = 1.0;
	x[0][1] = 0.0;
	x[0][2] = 0.0;
	
	x[1][0] = 0.0;
	x[1][1] = 2.0;
	x[1][2] = 0.0;
	
	x[2][0] = 0.0;
	x[2][1] = 0.0;
	x[2][2] = 3.0;
	cout << x;
	Matrix<double> xinv = x.inverse();
	cout << xinv;
	Matrix<double> y = x * xinv;
	cout << y;

	Matrix<double> pointsMatrix = readFile(argv[1]);
	Matrix<double> b (pointsMatrix.numRows, 1);
	
	for(int i = 0; i < pointsMatrix.numRows; i++)
	{
		b[i][0] = pointsMatrix[i][pointsMatrix.numCols -1];
		pointsMatrix[i][pointsMatrix.numCols-1] = 1;
	}
	
	Matrix<double> A (pointsMatrix);
	cout << A;
	Matrix<double> At = A.transpose();
	cout << "transpose" << At;
	//Matrix<double> Bhat = (A * At).inverse() * At * b;
	Matrix<double> Bhat = (At * A);
	Bhat = Bhat.inverse();
	Bhat = Bhat * At ;
	Bhat = Bhat * b;
	cout << Bhat;
}
