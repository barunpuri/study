#include <iostream>
#include <fstream>
#include <vector>

void magic_square_2k(std::ifstream& fin);
std::vector<int> make_4k(int size);
void make_4k_2(std::vector<int>& square, int size);
void make_res_4k(std::vector<int>& res, const std::vector<int>& reverse, int size);
void make_2k_1(std::vector<int>& square, int size);
void go_right_up(int& i, int& j, int size);
void go_left_down(int& i, int& j, int size);
std::vector<char> make_type(int size);
int calc(int loc, char type, int index);
void print(const std::vector<int>& square, int size);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		magic_square_2k(fin);
	fin.close();
	
	return 0;
}


void magic_square_2k(std::ifstream& fin)
{
	int size;
	fin >> size;

	std::vector<int> square;
	if( size%4 == 0 )
		square = make_4k(size);
	else //if(size%4 == 2)
		make_4k_2(square, size);

	print(square, size);
}

std::vector<int> make_4k(int size)
{
	std::vector<int> res;
	std::vector<int> reverse;
	int index;
	
	for( int i=0; i<size*size; ++i)
		res.push_back(i+1);

	for( int i=0; i<size*size; ++i)
	{
		index = res.size()-1-i;
		reverse.push_back(res[index]);
	}

	make_res_4k(res, reverse, size);

	return res;

}

void make_res_4k(std::vector<int>& res, const std::vector<int>& reverse, int size)
{
	int det[16] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
	int row, col;
	for( int i=0; i<res.size(); ++i)
	{
		row = i/size%4; 
		col = i%size%4;
		if( det[row*4+col] == 0 )
			res[i] = reverse[i];

	}	
}
////////////////////////////////////////////////////////////////////////////////////
void make_4k_2(std::vector<int>& square, int size)
{
	int half = size/2;
	std::vector<int> semi_square(half*half);
	make_2k_1( semi_square, half);
	std::vector<char> type = make_type(half);
	int data, index;	

	
	for(int i=0; i<half; ++i)
	{
		for( int j=0; j<half; ++j)
		{
			index = i*half +j;

			data = calc(semi_square[index],type[index],0);
			square.push_back(data);
			data = calc(semi_square[index],type[index],1);
			square.push_back(data);
		}

		for( int j=0; j<half; ++j)
		{
			index = i*half +j;

			data = calc(semi_square[index],type[index],2);
			square.push_back(data);
			data = calc(semi_square[index],type[index],3);
			square.push_back(data);
		}
	}
}

void make_2k_1(std::vector<int>& square, int size)
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

std::vector<char> make_type(int size)
{
	std::vector<char> type;
	int half = size/2;
	for(int i=0; i<size; ++i)
	{
		for( int j=0; j<size; ++j)
		{
			if( i<=half )
				type.push_back('L');
			else if( i == half+1 )
				type.push_back('U');
			else
				type.push_back('X');
		}
	}

	int index = size*(half+1) + (int)(size/2);
	
	type[index-size] = 'U';
	type[index] = 'L';
	
	return type;
}

int calc(int loc, char type, int index)
{
	std::vector<int> res(4);
	int starting_num = (loc-1)*4 +1;	
	
	if( type == 'L')
	{
		res[1] = starting_num;
		res[2] = starting_num+1;
		res[3] = starting_num+2;		
		res[0] = starting_num+3;
	}
	else if( type == 'U')
	{
		res[0] = starting_num;
		res[2] = starting_num+1;
		res[3] = starting_num+2;		
		res[1] = starting_num+3;
	}
	else //if( type == 'X')
	{
		res[0] = starting_num;
		res[3] = starting_num+1;
		res[2] = starting_num+2;		
		res[1] = starting_num+3;
	}

	return res[index];
}

void print(const std::vector<int>& square, int size)
{
	for( int i=0; i<size; ++i)
	{
		for( int j=0; j<size; ++j)
			std::cout << square[i*size+j] << " " ;
		std::cout << std::endl;
	}
}


