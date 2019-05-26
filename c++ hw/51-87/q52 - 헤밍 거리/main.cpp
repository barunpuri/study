#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

void hamming_dist(std::ifstream& fin);
std::vector<int> num_to_binary(int num);
int calc_weight(const std::vector<int> binary_num);
int calc_dist(const std::vector<int> binary_num_1, const std::vector<int> binary_num_2);
void print(const int weight_1, const int weight_2, const int dist);

int main()
{
	std::ifstream 	fin;
	int 		numTestCase;

	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hamming_dist(fin);
	fin.close();	

	return 0;
}

void hamming_dist(std::ifstream& fin)
{
	int num_1;//숫자 1
	int num_2;
	int dist;
	int weight_1;
	int weight_2;

	fin >> num_1 >> num_2;

	std::vector<int> binary_num_1;
	std::vector<int> binary_num_2; 

	binary_num_1 = num_to_binary(num_1);
	binary_num_2 = num_to_binary(num_2);

	weight_1 = calc_weight( binary_num_1 );
	weight_2 = calc_weight( binary_num_2 );

	dist = calc_dist( binary_num_1, binary_num_2);

//	for(int i=0; i<binary_num_1.size(); ++i)
//		std::cout << binary_num_1[i];
//	std::cout << std::endl;

//	for(int i=0; i<binary_num_2.size(); ++i)
//		std::cout << binary_num_2[i];
//	std::cout << std::endl;

	print( weight_1, weight_2, dist);

}

std::vector<int> num_to_binary(int num)
{
	std::vector<int> temp;
	for(int i=0; i<32; ++i)
	{
		if(  (int)( num / pow(2,(31-i)) ) == 0 )
		{
			temp.push_back(0);
			
		}
		else
		{
			temp.push_back(1);
			num = num % (int)pow(2,(31-i)) ;

		}
	}

	return temp;
}

int calc_weight(const std::vector<int> binary_num)
{
	int weight = 0;
	for(int i=0; i<binary_num.size(); ++i)
		if( binary_num[i] == 1 )
			weight++;

	return weight;
}

int calc_dist(const std::vector<int> binary_num_1, const std::vector<int> binary_num_2)
{
	int dist = 0;
	bool start = false;
	for(int i=0; i<binary_num_1.size(); ++i)
	{	
		if( binary_num_1[i] == binary_num_2[i] && !start )
			continue;
		else
			start = true;

		if( binary_num_1[i] != binary_num_2[i] )
			dist++;
	}

	return dist;
}

void print(const int weight_1, const int weight_2, const int dist)
{
	std::cout << weight_1 << " " << weight_2 << " " << dist << std::endl;
}
