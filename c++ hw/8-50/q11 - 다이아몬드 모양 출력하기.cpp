#include <iostream>
#include <fstream>

void hw_1_6(std::ifstream& fin);
void print(int i, int j, int size);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hw_1_6(fin);
	fin.close();
	
	return 0;

}

void hw_1_6(std::ifstream& fin)
{
	int size;
	fin >> size;

	for(int i=0; i<size; ++i)
	{
		for(int j=0; j<size; ++j)
		{
			print(i-size/2, j-size/2, size/2 ); //사각형의 중심을 (0,0)으로 만듦
		}
		std::cout << std::endl;
	}

}

void print(int i, int j, int size)
{
	if(i<0)
		i=i*(-1);
	if(j<0)
		j=j*(-1);

	if( (i+j) > size )
		std::cout << "*";
	else
		std::cout << "+";
}


























