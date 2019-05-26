#include <iostream>
#include <fstream>
#include <vector>

const int MAX_SIZE = 100;

void q37(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<char>& matrix, int size);
bool cf_x_axis(std::vector<char> original, int row, int col);
bool cf_y_axis(std::vector<char> original, int row, int col);
void print(bool x_axis, bool y_axis);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q37(fin);
	fin.close();
	
	return 0;

}

void q37(std::ifstream& fin)
{
	int row, col;
	fin >> row >> col ;
	
	std::vector<char> original;

	inputData(fin, original, row*col);
	
	bool x_axis = cf_x_axis(original, row, col);//상하
	bool y_axis = cf_y_axis(original, row, col);//좌우 

	print(x_axis, y_axis);
}

void inputData(std::ifstream& fin, std::vector<char>& matrix, int size)
{
	char temp;
	for(int i=0; i<size; ++i)
	{
		fin >> temp;
		matrix.push_back(temp);
	}
}

bool cf_x_axis(std::vector<char> original, int row, int col)
{
	bool result = true;
	for(int i=0; i<row/2; ++i)
	{	
		for(int j=0; j<col; ++j)
		{	
			if(original[i*col + j]!=original[(row-1-i)*col + j])
			{
				result = false;	
				break;
			}		
		}	
	}
	return result;
}

bool cf_y_axis(std::vector<char> original, int row, int col)
{
	bool result = true;
	for(int i=0; i<row; ++i)
	{	
		for(int j=0; j<col/2; ++j)
		{	
			if(original[i*col + j]!=original[i*col + (col-1-j) ])
			{
				result = false;	
				break;
			}
		}	
	}
	return result;
}

void print(bool x_axis, bool y_axis)
{	
	int result ;
	if( x_axis && y_axis )
		result = 3;
	else if( x_axis )
		result = 1;
	else if( y_axis ) 
		result = 2;
	else 
		result = 0;

	std::cout << result << std::endl;	
}





