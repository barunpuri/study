#include <iostream>
#include <fstream>
#include <vector>

void q31(std::ifstream& fin);
void getPrimeNums(std::vector<int>& primeNums, std::vector<int>& countFactors);
bool detPrime(int number);
void primeFac(int num, std::vector<int>& primeNums, std::vector<int>& countFactors);
void print(std::vector<int>& primeNums, std::vector<int>& countFactors);
int countNumFactors(std::vector<int>& countFactors);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q31(fin);
	fin.close();
	
	return 0;

}

void q31(std::ifstream& fin)
{
	int num;
	fin >> num;

	std::vector<int> primeNums;
	std::vector<int> countFactors; 
	
	getPrimeNums(primeNums, countFactors);
	
	primeFac(num, primeNums, countFactors);

	int numFactors = countNumFactors(countFactors);
	std::cout << numFactors << " ";

	print(primeNums, countFactors);
}

void getPrimeNums(std::vector<int>& primeNums, std::vector<int>& countFactors)
{
	for(int i=2; i<10000; ++i)
	{
		if( detPrime(i) )
			primeNums.push_back(i);
			countFactors.push_back(0);
	}
}

bool detPrime(int number)
{
	bool isPrime = true;
	for(int i=2; i*i <= number; ++i)
	{
		if(number%i==0)
			isPrime = false;		
	}
	
	return isPrime;
}


void primeFac(int num, std::vector<int>& primeNums, std::vector<int>& countFactors)
{	
	
	for(int i=0; i<primeNums.size();++i)
	{
		if(num%primeNums[i]==0)
		{	
			countFactors[i]++; 
			num = num/primeNums[i];
			--i;
		}
	}
}

void print(std::vector<int>& primeNums, std::vector<int>& countFactors)
{
	for(int i=0; i<primeNums.size(); ++i)
	{
		if(countFactors[i]!=0)
			std::cout << primeNums[i] << " " << countFactors[i] << " ";

	}
	std::cout << std::endl;
}

int countNumFactors(std::vector<int>& countFactors)
{
	int count = 0;
	for(int i=0; i<countFactors.size(); ++i)
	{
		if(countFactors[i]!=0)
		count++;
	}
	return count;
}
