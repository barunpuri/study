#include <iostream>
#include <fstream>

void q21(std::ifstream& fin);
int calc(unsigned long long Int1, unsigned long long Int2, int& numZero);

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
	
	unsigned long long Int1=1;
	unsigned long long Int2;
	int numZero=0;
	for(int i=0; i<numInts; ++i)
	{
		fin >> Int2;
		Int1 = calc(Int1, Int2, numZero);
	
	}
	
	std::cout << Int1%10 << " " << numZero << std::endl;
}

int calc(unsigned long long Int1, unsigned long long Int2, int& numZero)
{
	unsigned long long multi = Int1 * Int2;
	
	while(true)
	{
		if(multi%10==0)
		{
			multi = multi/10;
			numZero += 1;
		}
		else
			break;
	}
	return multi;
}







