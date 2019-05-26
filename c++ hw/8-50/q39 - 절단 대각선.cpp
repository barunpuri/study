#include <iostream>
#include <fstream>
#include <vector>

void q39(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<int>& matrix, int size);
int calc(const std::vector<int>& matrix, int size);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q39(fin);
	fin.close();
	
	return 0;

}

void q39(std::ifstream& fin)
{
	int size;
	fin >> size;

	int maxSum=0;
	std::vector<int> matrix;

	inputData(fin, matrix, size);
	
	maxSum = calc(matrix, size);

	std::cout << maxSum << std::endl;
	
}

void inputData(std::ifstream& fin, std::vector<int>& matrix, int size)
{	int data;
	for(int i=0; i<size; ++i)
	{
		for(int j=0; j<size; ++j)
		{		
			fin >> data;
			matrix.push_back(data);
		}	
	}
}

int calc(const std::vector<int>& matrix, int size)
{	
	int maxSum=0;
	int row=0;

	for(int i=0; i<size; ++i) // \방향 size개 
	{
		int sum=0;
		for(int j=0; j<size; ++j)
		{
			row = i+j;
			if(row>=size)
				row = row - size;
			sum += matrix[row*size + j];

		}
	
		if(sum > maxSum)
			maxSum = sum;

	}

	for(int i=0; i<size; ++i) // /방향 size개
	{
		int sum=0;
		for(int j=0; j<size; ++j)
		{
			row = i+j;
			if(row>=size)
				row = row - size;	
			sum += matrix[row*size + size-1-j];
			
		}
	
		if(sum > maxSum)
			maxSum = sum;
	}
	

	return maxSum;
}

