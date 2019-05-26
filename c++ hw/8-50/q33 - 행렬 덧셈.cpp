#include <iostream>
#include <fstream>
#include <vector>


void q33(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<int>& vector, int size);
void sumMatrix(std::vector<int> A, std::vector<int> B, std::vector<int>& sum, int size);
void print(std::vector<int> vector, int row, int col);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q33(fin);
	fin.close();
	
	return 0;

}

void q33(std::ifstream& fin)
{
	int row, col;
	fin >> row >> col ;
	
	std::vector<int> A;
	std::vector<int> B;
	std::vector<int> sum;

	inputData(fin, A, row*col);
	inputData(fin, B, row*col);
	
	sumMatrix(A, B, sum, row*col);
	print( sum, row, col );
}

void inputData(std::ifstream& fin, std::vector<int>& matrix, int size)
{	
	int data;
	for(int i=0; i<size; ++i)
	{
		fin >> data;
		matrix.push_back(data);
	}
}

void sumMatrix(std::vector<int> A, std::vector<int> B, std::vector<int>& sum, int size)
{
	for(int i=0; i<size; ++i)
	{
		sum.push_back(A[i] + B[i]);
	}

}

void print(std::vector<int> matrix, int row, int col)
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			std::cout << matrix[i*col + j] << " " ;
		
		std::cout << std::endl;
	}
	
}








