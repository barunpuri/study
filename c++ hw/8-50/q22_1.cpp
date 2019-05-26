#include <iostream>
#include <fstream>

void q21(std::ifstream& fin);
int divid_2(int Int1, int& numTwo);
int divid_5(int Int1, int& numFive);
void calc(int Int, int numTwo, int numFive);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q21(fin);
	fin.close();
	
	return 0;
}

void q21(std::ifstream& fin)
{
	int numInts;
	fin >> numInts;
	
	int Int1=1;
	int Int2;
	int numTwo=0;
	int numFive=0;
	for(int i=0; i<numInts; ++i)
	{
		fin >> Int2;
		Int2 = divid_2(Int2, numTwo);
		Int2 = divid_5(Int2, numFive);
		Int2 = Int2%10;
		Int1 = Int1 * Int2;
		Int1 = Int1%10;
	}
	
	calc(Int1, numTwo, numFive);
}

int divid_2(int Int1, int& numTwo)
{
	while(true)
	{
		if(Int1%2==0)
		{
			Int1 = Int1/2;
			numTwo += 1;
		}
		else
			break;
	}
	return Int1;
}

int divid_5(int Int1, int& numFive)
{
	while(true)
	{
		if(Int1%5==0)
		{
			Int1 = Int1/5;
			numFive += 1;
		}
		else
			break;
	}
	return Int1;
}

void calc(int Int, int numTwo, int numFive)
{
	int numZero;
	if(numTwo < numFive)
	{
		numZero = numTwo;
		for(int i=0; i<(numFive-numTwo); ++i)
		{
			Int = 5;
		}		
	}
	else
	{
		numZero = numFive;
		for(int i=0; i<(numTwo-numFive); ++i)
		{
			Int = Int * 2;
			Int = Int % 10;
		}	
	}
	
	std::cout << Int%10 << " " << numZero << std::endl;
}







