#include <iostream>
#include <fstream>
#include <vector>

const int MAX_SIZE = 100;

void q38(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<char>& field, int size);
void progress(std::vector<char>& field, int times, int row, int col);
void spread(std::vector<char>& passed, int row, int col);
void predict(std::vector<char> passed, std::vector<char>& current, int i, int j, int col);
char update(std::vector<char> passed, std::vector<char> current, int i, int j, int col);
void outputData(std::vector<char> field, int row, int col);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q38(fin);
	fin.close();
	
	return 0;

}

void q38(std::ifstream& fin)
{
	int row, col, times;
	fin >> col >> row >> times;

	std::vector<char> field;

	inputData(fin, field, row*col);
	
	progress(field, times-1, row, col);

	outputData(field, row, col);	
}

void inputData(std::ifstream& fin, std::vector<char>& field, int size)
{
	for(int i=0; i<size; ++i)
	{	
		char situ;
		fin >> situ;
		field.push_back(situ);
	}
}
	
void progress(std::vector<char>& field, int times, int row, int col)
{
	for(int i=0; i<times; ++i)
		spread(field, row, col);

}

void spread(std::vector<char>& passed, int row, int col)
{	
	std::vector<char> current(passed.size()); 
	std::vector<char> coming;
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			predict(passed, current, i, j, col);
	}

	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			coming.push_back( update(passed, current, i, j, col) );

	}
	
	passed.swap(coming);
	coming.clear();
			
}

void predict(std::vector<char> passed, std::vector<char>& current, int i, int j, int col)
{
	if( passed[i*col + j] == '*')
	{
		if(i>0)
			current[(i-1)*col + j] = '*';
		current[(i+1)*col + j] = '*';

		if( (j!=0)&&(j!=col-1) )
		{
			current[i*col + j-1] = '*';		
			current[i*col + j+1] = '*';
		}
		
		current[i*col + j]   = '+';
	}
}

char update(std::vector<char> passed, std::vector<char> current, int i, int j, int col)
{
	if( (passed[i*col + j] == '*')||(passed[i*col + j] == '+') )
		return '+';
	else if( (passed[i*col + j] == 'O')&&(current[i*col + j] == '*') )
		return '*';
	else 
		return 'O';
}

void outputData(std::vector<char> field, int row, int col)
{	
	int numBurning = 0;
	int numBurned = 0;
	for(int i=0; i<row*col; ++i)
	{
		if(field[i]== '*')
			numBurning += 1;
		if(field[i]== '+')
			numBurned += 1;
	}

	std::cout << numBurning << " " << numBurned << std::endl;

	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
			std::cout << field[i*col + j] ;
		
		std::cout << std::endl;
	}
}









