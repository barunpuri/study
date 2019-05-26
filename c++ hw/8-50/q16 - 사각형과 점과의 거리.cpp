#include <iostream>
#include <fstream>

void q16(std::ifstream& fin);
void calc(int x1, int y1, int x2, int y2, int x, int y);
bool in_range(int start, int end, int point);
int calc_length(int start , int end, int point);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q16(fin);
	fin.close();
	
	return 0;

}

void q16(std::ifstream& fin)
{
	int x1, y1, x2, y2, x, y;
	fin >> x1 >> y1 >> x2 >> y2;
	fin >> x >> y;
	
	calc(x1, y1, x2, y2, x, y);
	
}

void calc(int x1, int y1, int x2, int y2, int x, int y)
{
	bool inRectX, inRectY;
	inRectX = in_range(x1, x2, x);
	inRectY = in_range(y1, y2, y);

	int resultX, resultY;

	if( inRectX && inRectY ) 
		std::cout << "0 0" << std::endl;
	else if( inRectX )
	{
		resultY = calc_length(y1, y2, y);
		std::cout << resultY*resultY << " " << resultY <<std::endl;
	}
	else if( inRectY )
	{
		resultX = calc_length(x1, x2, x);
		std::cout << resultX*resultX << " " << resultX <<std::endl;
	}
	else 
	{
		resultX = calc_length(x1, x2, x);
		resultY = calc_length(y1, y2, y);
		std::cout << resultX*resultX + resultY*resultY << " "  << resultX +resultY <<std::endl;
		
	}
}

bool in_range(int start, int end, int point)
{
	if( (start <= point)&&(point <= end) )
		return true; 	
	else
		return false;
}

int calc_length(int start , int end, int point)
{
	if(end < point)
		return point-end;
	else if( point < start )
		return start-point;
	
}

