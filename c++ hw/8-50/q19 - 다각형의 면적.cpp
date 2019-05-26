#include <iostream>
#include <fstream>

void q19(std::ifstream& fin);
int calc(int x[], int y[], int numCoord);
int det(int result);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q19(fin);
	fin.close();
	
	return 0;

}

void q19(std::ifstream& fin)
{
	int numCoord=0;
	fin >> numCoord;
	
	int x[numCoord+1];
	int y[numCoord+1];
	
	for(int i=0; i<numCoord; ++i)
	{
		fin >> x[i] >> y[i];
	}

	x[numCoord] = x[0];
	y[numCoord] = y[0];

	int result;
	result = calc(x,y,numCoord);
	
	int direction;
	direction = det(result);
	
	std::cout << result*direction << " " << direction << std::endl;
}

int calc(int x[], int y[], int numCoord)
{
	int area=0;
	for(int i=0; i<numCoord; ++i)
	{
		area = area + (x[i]+x[i+1])*(y[i+1]-y[i]);	
	}
	return area;
}

int det(int result)
{
	if(result == 0)
		return 0;
	else if(result < 0)
		return -1;
	else 
		return 1;

}
