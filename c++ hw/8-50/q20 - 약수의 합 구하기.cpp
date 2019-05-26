#include <iostream>
#include <fstream>
#include <math.h>

void q20(std::ifstream& fin);
void count(int num);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q20(fin);
	fin.close();
	
	return 0;

}

void q20(std::ifstream& fin)
{
	int number;
	fin >> number;
	
	count(number);
}

void count(int num)
{
	int sum=0; 
	int amount=0;
	
	if( sqrt(num)-(int)sqrt(num) ==0)
	{
		amount +=1;
		sum += sqrt(num);
	}		
	
	for(int i=1; i<sqrt(num); ++i)
	{
		if((num%i)==0)
		{
			sum += i;
			sum += num/i ;
			amount += 2;					
		}
	}
	std::cout << amount -1 << " " << sum -num << std::endl;
}







