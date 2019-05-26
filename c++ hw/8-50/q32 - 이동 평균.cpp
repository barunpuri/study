#include <iostream>
#include <fstream>
#include <vector>

void q32(std::ifstream& fin);
void getData(std::ifstream& fin, std::vector<int>& Ints, int numInts);
void calc(std::vector<int>& Ints,int numInts, int divide);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q32(fin);
	fin.close();
	
	return 0;

}

void q32(std::ifstream& fin)
{
	int numInts;
	fin >> numInts;

	std::vector<int> Ints;

	getData(fin, Ints, numInts);	
	
	int divide;
	fin >> divide;
	
	calc(Ints, numInts, divide);
	
}

void getData(std::ifstream& fin, std::vector<int>& Ints, int numInts)
{
	int num;
	for(int i=0; i<numInts; ++i)
	{
		fin >> num;
		Ints.push_back(num);	
	}		
}

void calc(std::vector<int>& Ints,int numInts, int divide)
{
	int count = numInts - divide +1;	
	
	std::cout << count << " ";
	for(int i=0; i<numInts - divide +1; ++i)
	{
		int avg=0;
		for(int j=i; j<i+divide; ++j)
		{	
			avg += Ints[j];
		}
		std::cout << avg/divide << " ";
	}

	std::cout << std::endl;

}




