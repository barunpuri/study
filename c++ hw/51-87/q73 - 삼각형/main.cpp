#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

void triangle(std::ifstream& fin);
int calc_area(int ax, int ay, int bx, int by, int cx, int cy);
void sort(int& AB, int& BC, int& CA);
int det_tri_1(int a, int b, int c);
int det_tri_2(int AB, int BC, int CA);
int det_point_position(int ax, int ay, int bx, int by, int cx, int cy, int x, int y);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		triangle(fin);
	fin.close();
	
	return 0;

}

void triangle(std::ifstream& fin)
{
	int ax, ay, bx, by, cx, cy, x, y;
	fin >> ax >> ay >> bx >> by >> cx >> cy >> x >> y;
	
	int area;
	area = calc_area(ax, ay, bx, by, cx, cy);

	int AB, BC, CA;
	AB = (bx-ax)*(bx-ax) + (by-ay)*(by-ay);
	BC = (cx-bx)*(cx-bx) + (cy-by)*(cy-by);
	CA = (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy);

	sort( AB, BC, CA);

	int kindTri1, kindTri2;
	kindTri1 = det_tri_1(AB, BC, CA);

	if( kindTri1 == 0)
		kindTri2 = 0;
	else
		kindTri2 = det_tri_2(AB, BC, CA);

	int pointPosition=0;
	pointPosition = det_point_position(ax, ay, bx, by, cx, cy, x, y);

	if( area == 0 )
		std::cout << 0 << std::endl;
	else		
		std::cout << area << " " << kindTri1 << " " << kindTri2 << " " << pointPosition << std::endl ;
	
	
}

int calc_area(int ax, int ay, int bx, int by, int cx, int cy)
{
	int area;
	area = ( (bx-ax)*(cy-ay) - (cx-ax)*(by-ay) ) ;

	area = std::abs(area);
	return area;
}

void sort(int& AB, int& BC, int& CA)
{
	int tmp;

	if( AB > CA )
	{
		tmp = CA;
		CA = AB;
		AB = tmp;
	}

	if( AB > BC )
	{
		tmp = AB;
		AB = BC;
		BC = tmp;
	}

	if( BC > CA )
	{
		tmp = BC;
		BC = CA;
		CA = tmp;
	}

}

int det_tri_1(int a, int b, int c)
{
	if(sqrt(a)+sqrt(b) <= sqrt(c))
		return 0;
	else if( a + b == c)
		return 2;
	else if(a==c)
		return 1;
	else if(a==b || b==c)
		return 3;
	else
		return 4;	

}

int det_tri_2(int AB, int BC, int CA)
{
	if( AB + BC == CA)
		return 1;
	else if ( AB + BC < CA)
		return 2;
	else 
		return 3;

}

int det_point_position(int ax, int ay, int bx, int by, int cx, int cy, int x, int y)
{
	int area1, area2, area3, originArea;

	originArea = calc_area(ax, ay, bx, by, cx, cy);
	area1 = calc_area(ax, ay, bx, by, x, y);
	area2 = calc_area(ax, ay, x, y, cx, cy);
	area3 = calc_area(x, y, bx, by, cx, cy);

	originArea = std::abs(originArea);
	area1 = std::abs(area1);
	area2 = std::abs(area2);	
	area3 = std::abs(area3);

	
	if( area1 == 0 || area2 == 0 || area3 == 0 )
		return 2;
	else if( originArea == area1+area2+area3 )
	{	
		//std::cout << "is in tri" ;	
		return 1;
	}	
	else
	{	//std::cout << "isn't in tri";
		return 3;
	}
	
}




