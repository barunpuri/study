#include <iostream>
#include <fstream>

void q21(std::ifstream& fin);

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
	int number;
	fin >> number;

	bool isPrime = true;
	for(int i=2; i*i <= number; ++i)
	{
		if(number%i==0)
			isPrime = false;		
	}
	
	std::cout << isPrime << std::endl;
}


