#include <iostream>
#include <fstream>

void hw_1_5(std::ifstream& fin);
void print(int i, int j, int size );

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hw_1_5(fin);
	fin.close();
	
	return 0;

}

void hw_1_5(std::ifstream& fin)
{
	int size;
	fin >> size ;
	
	for(int i=0; i<size; ++i)
	{
		for(int j=0; j<size; ++j)
		{
			print(i, j, size-1);
		}
		std::cout << std::endl;
	}

}


void print(int i, int j, int size )
{
	if( ( i>j || (size-i) < j) && (i<j || (size-i) > j) )
		std::cout << "-";
	else if( (i+j)%2==0)
		std::cout << "*";
	else
		std::cout << "+";


}
