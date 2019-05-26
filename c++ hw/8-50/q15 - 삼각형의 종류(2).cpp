#include <iostream>
#include <fstream>
#include <cmath>

void q15(std::ifstream& fin);
void calc(int ax, int ay, int bx, int by, int cx, int cy);
void det(int AB, int BC, int CA);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q15(fin);
	fin.close();
	
	return 0;

}

void q15(std::ifstream& fin)
{
	int ax,ay,bx,by,cx,cy;
	fin >> ax >> ay >> bx >> by >> cx >> cy;
	
	calc(ax,ay,bx,by,cx,cy);
	
}

void calc(int ax, int ay, int bx, int by, int cx, int cy)
{
	int AB, BC, CA, tmp;
	AB = (bx-ax)*(bx-ax) + (by-ay)*(by-ay);
	BC = (cx-bx)*(cx-bx) + (cy-by)*(cy-by);
	CA = (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy);
	
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

	det(AB, BC, CA); //AB <= BC <= CA

}

void det(int AB, int BC, int CA)
{
	float ab, bc, ca;
	ab = sqrt(AB);
	bc = sqrt(BC);
	ca = sqrt(CA);
	if( ab + bc <= ca )
		std::cout << "0" << std::endl;
	else if( AB + BC == CA)
		std::cout << "1" << std::endl;
	else if ( AB + BC < CA)
		std::cout << "2" << std::endl;
	else 
		std::cout << "3" << std::endl;

}







