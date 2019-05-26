#include <iostream>
#include <fstream>
#include <vector>

void magic_square(int size);
void make_magic_square(std::vector<int>& square, int size);
void go_right_up(int& i, int& j, int size);
void go_left_down(int& i, int& j, int size);
void print(const std::vector<int>& square, int size);

int main()
{
	std::ifstream	fin;
	int		numTestCase;
	int 		size;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
	{
		fin >> size;	
		magic_square(size);
	}
	fin.close();

	return 0;
}

void magic_square(int size)
{
	std::vector<int> square;
	square.assign(size*size,0);

	make_magic_square(square, size);

	print(square, size);
}

void make_magic_square(std::vector<int>& square, int size)
{	
	int loc;
	int i=0; 
	int j=size/2;
	
	for(int num=1; num<=size*size; ++num)
	{
		if( square[i*size + j] != 0 )
		{
			go_left_down(i,j,size);
			++i;
		}

		loc = i*size + j;
		square[loc] = num;	
		go_right_up(i,j,size);		
		
	}
}

void go_right_up(int& i, int& j, int size)
{
	--i;
	++j;
	if( i<0 ) 
		i += size;
	if( j>=size )
		j -= size;
}

void go_left_down(int& i, int& j, int size)
{
	++i;
	--j;
	if( i>=size )
		i -= size;

	if( j<0 ) 
		j += size;
}


void print(const std::vector<int>& square, int size)
{
	for(int i=1; i<=square.size(); ++i)
	{
		std::cout << square[i-1] << " ";
		if( i % size == 0 )
			std::cout << std::endl;
	}
}
