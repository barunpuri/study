#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

void hamming_code(std::ifstream& fin);
void num_to_binary(unsigned int num, std::vector<int>& binary);
void det_code_loc(std::vector<int>& binary);
int num_odd_num(const std::vector<int>& binary, int index);
unsigned int binary_to_num(const std::vector<int>& binary);
unsigned int encode(unsigned int data);
unsigned int decode(unsigned int data);
int det_correct_code(const std::vector<int>& binary);

int main()
{
	std::ifstream 	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hamming_code(fin);
	fin.close();
	
	return 0;

}

void hamming_code(std::ifstream& fin)
{
	int type; 
	unsigned int data;
	unsigned int res;

	fin >> type >> data;	// 0: encode , 1: decode
	if( type == 0 ) 
		res = encode(data);
	else if( type == 1 )
		res = decode(data);

	std::cout << res << std::endl;

}

void num_to_binary(unsigned int num, std::vector<int>& binary) //encode, decode 사용
{
	int num_2=0;
	for(int i=0; i<binary.size(); ++i)
	{
		if( binary[i] == 2 )
			num_2 = num_2 +1;
	}	

	int loc=binary.size()-1;
	int index;
	for(int i=0; i<binary.size()-num_2; ++i)
	{
		index = binary.size()-num_2-1-i;

		if( binary[loc] == 2)
		{
			loc = loc -1;
		}
		binary[loc] = num/pow(2,index);
		num = num % (int)pow(2,index) ;
		loc = loc -1;
	}
}

void det_code_loc(std::vector<int>& binary) // 왼쪽이 작은수 
{
	int loc = 0;
	for(int i=0; i<binary.size(); ++i)
	{
		if(i==pow(2,loc)-1)
		{
			binary[i] = 2;
			++loc;
		}
	}	
}

int num_odd_num(const std::vector<int>& binary, int index) //홀수
{
	int res =0;
	for(int i=index-1; i<binary.size(); i+=index)
	{
		for( int j=0; j<index; ++j)
		{		
			if( binary[i+j] == 1 )
				res += 1;
		}		
		i += index;
	}

	return res;
}

unsigned int binary_to_num(const std::vector<int>& binary)
{
	unsigned int res=0;
	int num_pBit=0;
	for(int i=0; i<binary.size(); ++i)
	{
		if( binary[i] == 2 )
		{
			num_pBit += 1;
			continue;
		}		
		res += binary[i]*pow(2,i-num_pBit);
	}

	return res;
}

unsigned int encode(unsigned int data)
{
	unsigned int res=0;
	std::vector<int> binary(31,3);//32개의 3 //3:데이터 자리 //2:code자리 
	
	det_code_loc(binary);
	num_to_binary(data, binary);
	
	for(int i=0; i<binary.size(); ++i)
	{
		if(binary[i] == 2)
			binary[i] = num_odd_num(binary, i+1)%2;
	}

	res = binary_to_num(binary);

	return res;
}

unsigned int decode(unsigned int data)
{
	unsigned int res =0;
	std::vector<int> binary(31,3);//32개의 3 //3:데이터 자리 //2:code자리 
	
	num_to_binary(data, binary);
	int wrong_coord = det_correct_code(binary);

	if(wrong_coord != 0)
		binary[wrong_coord-1] = (binary[wrong_coord-1]+1)%2;

	det_code_loc(binary);
	res = binary_to_num(binary);

	return res;
}	

int det_correct_code(const std::vector<int>& binary) //맞으면 0, 틀리면 틀린자리 +1 ;
{
	int res=0;
	int power=0;	
	for(int i=0; i<binary.size(); ++i)
	{
		if( i == pow(2,power)-1 ) 
		{
			if( num_odd_num(binary, i+1)%2 != 0 )
				res += i+1;
			power += 1;
		}
	}

	return res;
}
