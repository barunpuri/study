#include <iostream>
#include <fstream>

void hw_1_3(std::ifstream& fin);
int calc_elem(int i, int j, int k);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hw_1_3(fin);
	fin.close();
	
	return 0;

}

void hw_1_3(std::ifstream& fin)
{
	int	k;

	fin >> k;
	for (int i=0; i<k; ++i)
	{
		for(int j=0; j<=i; ++j)
		{
			int 	elem;

			elem = calc_elem(i+1,j+1,k); //1행 2행 ..... < i,j가 0부터 카운트
			std::cout << elem << " " ;
		}
		std::cout << std::endl;
	}	
}

int calc_elem(int i, int j, int k)
{
	int calc=0;
	
	calc = (j-1)*k - (j-1)*(j-2)/2;  //j열 전까지 숫자의 합 계산
	calc += i-j+1;   //행의 값계산
	
	return calc;

}
