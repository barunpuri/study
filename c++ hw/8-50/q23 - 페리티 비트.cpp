#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

void q23(std::ifstream& fin);
long calc(int num);

int main()
{
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q23(fin);
	fin.close();

	return 0;
}

void q23(std::ifstream& fin)
{
	int num;
	long res;
	fin >> num;

	res = calc(num);

	std::cout << res << std::endl;
	
}

long calc(int num)
{
	int original = num;
	std::vector<int> binary;
	int cnt_1=1;
	
	for(int i=0; num > 1; ++i)
	{
		binary.push_back(num%2);
		if(binary[i] == 1)
			cnt_1 += 1;
		num = num/2;
	}
	
	binary.push_back(num);

	if( ( cnt_1 % 2 == 1  )&&( original != 0 ) )
		return original + pow(2,31);
	else 
		return original ;

}






