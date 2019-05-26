#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

void check_sum(std::ifstream& fin);
std::vector<int> num_to_binary(unsigned int num);
std::vector<int> binary_to_bytes(const std::vector<int>& binaryNum);
int calc_chech_sum(const std::vector<int>& bytes);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		check_sum(fin);
	fin.close();
	
	return 0;
}

void check_sum(std::ifstream& fin)
{
	unsigned int num;
	std::vector<int> binaryNum;
	std::vector<int> bytes;
	int checkSum;

	fin >> num;
	binaryNum = num_to_binary(num);

	bytes = binary_to_bytes(binaryNum);
	
	checkSum = calc_chech_sum(bytes);
	

	if( checkSum == bytes[bytes.size()-1] )
		std::cout << 1 << std::endl;
	else
		std::cout << 0 << std::endl;
	
}

std::vector<int> num_to_binary(unsigned int num)
{
	std::vector<int> res;
	for(int i=0; i<32; ++i)
	{
		if(  (int)( num / pow(2,(31-i)) ) == 0 )
		{
			res.push_back(0);
			
		}
		else
		{
			res.push_back(1);
			num = num % (int)pow(2,(31-i)) ;

		}
	}

	return res;
}

std::vector<int> binary_to_bytes(const std::vector<int>& binaryNum)
{
	std::vector<int> res;
	int byteData = 0;
	
	for(int i=0; i<binaryNum.size(); ++i)
	{
		if( (i%8 == 0)&&(i != 0) )
		{
			res.push_back(byteData);
			byteData = 0;
		}	
		byteData = byteData + binaryNum[i]*pow(2, 8-1-(i%8));
	}
	
	res.push_back(byteData);

	return res;
}

int calc_chech_sum(const std::vector<int>& bytes)
{
	int checkSum = 0 ;
	
	for( int i=0; i<bytes.size()-1; ++i)
		checkSum += bytes[i];

	while(checkSum >= 256) 
		checkSum -= 256;

	checkSum = 255 - checkSum;

	return checkSum;

}



