#include <iostream>
#include <fstream>

void q17(std::ifstream& fin);
bool in_range(int point1, int point2 , int point);
void calc(int Ax1, int Ay1, int Ax2, int Ay2, int Bx1, int By1, int Bx2, int By2);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q17(fin);
	fin.close();
	
	return 0;

}

void q17(std::ifstream& fin)
{
	int Ax1, Ay1, Ax2, Ay2;
	int Bx1, By1, Bx2, By2;

	fin >> Ax1 >> Ay1 >> Ax2 >> Ay2;
	fin >> Bx1 >> By1 >> Bx2 >> By2;

	calc(Ax1, Ay1, Ax2, Ay2, Bx1, By1, Bx2, By2);
}

bool in_range(int point1, int point2 , int point)
{
	if(point1 < point2)
	{
		if( (point1 <= point)&&(point <= point2) )
			return true;
		else
			return false;
	}
	else
	{
		if( (point2 <= point)&&(point <= point1) )
			return true;
		else
			return false;	
	}
}	

void calc(int Ax1, int Ay1, int Ax2, int Ay2, int Bx1, int By1, int Bx2, int By2)
{
	if(Ax1 == Ax2)
	{
		if( in_range(Ay1, Ay2, By1) && in_range(Bx1, Bx2, Ax1) )
		{
			if( (Ax1==Bx1)||(Ax1==Bx2)||(Ay1==By1)||(Ay2==By1) )
				std::cout << "2" << std::endl;
			else
				std::cout << "1" << std::endl;
		}
		else
			std::cout << "0" << std::endl;
	}
	else
	{
		if( in_range(Ax1, Ax2, Bx1) && in_range(By1, By2, Ay1) )
		{
			if( (Ay1==By1)||(Ay1==By2)||(Ax1==Bx1)||(Ax2==Bx1) )
				std::cout << "2" << std::endl;
			else
				std::cout << "1" << std::endl;
		}
		else
			std::cout << "0" << std::endl;
	}

}

