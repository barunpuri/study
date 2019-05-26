#include <iostream>
#include <fstream>
#include <vector>

void q34(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<int>& matrix, int size);
void sumMatrix(std::vector<int> A, std::vector<int> B, std::vector<int>& res, int row, int mid, int col);
void print(std::vector<int> matrix, int row, int col);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q34(fin);
	fin.close();
	
	return 0;

}

void q34(std::ifstream& fin)
{
	int row, mid, col;
	fin >> row >> mid >> col ;
	
	std::vector<int> A;
	std::vector<int> B;
	std::vector<int> sum;

	inputData(fin, A, row*mid);
	inputData(fin, B, mid*col);
	
	sumMatrix(A, B, sum, row, mid, col);
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

void sumMatrix(std::vector<int> A, std::vector<int> B, std::vector<int>& res, int row, int mid, int col)
{	

	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{	
			int sum=0;
			for(int k=0; k<mid; ++k)
				sum += A[i*mid + k] * B[k*col + j];
			res.push_back(sum);
		}
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








