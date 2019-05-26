#include <iostream>
#include <fstream>
#include <cstdlib>

void Two_dim_point(std::ifstream& fin);
int check_no_dist(int x1, int y1, int x2, int y2);
int calc_euclidean_dist(int x1, int y1, int x2, int y2);
int calc_rectilinear_dist(int x1, int y1, int x2, int y2);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		Two_dim_point(fin);
	fin.close();
	
	return 0;

}

void Two_dim_point(std::ifstream& fin)
{
	int x1, y1, x2, y2;
	fin >> x1 >> y1 >> x2 >> y2 ;
	
	int res;
	res = check_no_dist(x1, y1, x2, y2);
	std::cout << res << " ";

	res = calc_euclidean_dist(x1, y1, x2, y2);
	std::cout << res << " ";

	res = calc_rectilinear_dist(x1, y1, x2, y2);
	std::cout << res << " ";

	res = calc_euclidean_dist(x1, y1, y1, x1);
	std::cout << res << " ";

	res = calc_rectilinear_dist(x1, y1, y1, x1);
	std::cout << res << " ";
	
	std::cout << std::endl;
	
}

int check_no_dist(int x1, int y1, int x2, int y2)
{
	if( (x1 == x2)&&(y1==y2) )
		return 1;
	else 
		return 0;
}

int calc_euclidean_dist(int x1, int y1, int x2, int y2)
{
	int res;
	
	res = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

	return res;
}

int calc_rectilinear_dist(int x1, int y1, int x2, int y2)
{
	int res;

	res = std::abs(x1-x2) + std::abs(y1-y2);
	
	return res;
}
