#include <iostream>
#include <fstream>

void hw_1_1(std::ifstream& fin);
void print(int i, int j, int size);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hw_1_1(fin);
	fin.close();
	
	return 0;

}

void hw_1_1(std::ifstream& fin)
{
	int size = 0;
	fin >> size;
	for(int i=0; i<size; ++i)
	{
		for(int j=0; j<size; ++j)			
		{	
			print(i,j,size);
		}
		std::cout << std::endl;
	}		

}

void print(int i, int j, int size)
{
	
	if( i==size/2 && j==size/2)
		std::cout << "O" ;
	else if(size-1-i==j)
		std::cout << "*" ;
	else if(i==size/2)
		std::cout << "+" ;
	else if(j==size/2)
		std::cout << "I" ;
	else
		std::cout << ".";


}

