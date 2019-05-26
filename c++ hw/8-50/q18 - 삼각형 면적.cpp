#include <iostream>
#include <fstream>

void q18(std::ifstream& fin);
int calc(int ax, int ay, int bx, int by, int cx, int cy);
int det(int result);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q18(fin);
	fin.close();
	
	return 0;

}

void q18(std::ifstream& fin)
{
	int ax, ay, bx, by, cx, cy;
	fin >> ax >> ay >> bx >> by >> cx >> cy;
	
	int result;
	result = calc(ax, ay, bx, by, cx, cy);
	
	int direction;
	direction = det(result);
	
	std::cout << result*direction << " " << direction << std::endl;
}

int calc(int ax, int ay, int bx, int by, int cx, int cy)
{
	int area;
	area = ( (bx-ax)*(cy-ay) - (cx-ax)*(by-ay) ) ;
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


