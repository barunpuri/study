#include <iostream>
#include <fstream>


int hw_1_4(std::ifstream& fin);
int calc_tri(int a, int b, int c);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		std::cout << hw_1_4(fin) << std::endl;
	fin.close();
	
	return 0;

}

int hw_1_4(std::ifstream& fin)
{
	int a,b,c;
	fin >> a >> b >> c;
	
	return calc_tri(a,b,c);
}

int calc_tri(int a, int b, int c)
{
	if(a+b <= c)
		return 0;
	else if( (a*a + b*b) == c*c)
		return 2;
	else if(a==c)
		return 1;
	else if(a==b || b==c)
		return 3;
	else
		return 4;	

}
