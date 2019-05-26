#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

void cross_line(std::ifstream& fin);
void input_data(std::ifstream& fin , std::vector< std::pair<int, int> >& data);
int check(const std::pair<int, int>& point_1, const std::pair<int, int>& point_2, const std::pair<int, int>& point_3);


int main()
{
	std::ifstream	fin;
	int		numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		cross_line(fin);
	fin.close();
	
	return 0;

}

void cross_line(std::ifstream& fin)
{
	std::vector< std::pair<int, int> > data;
	input_data(fin, data);

	int res1=1;
	res1 *= check(data[0], data[1], data[2]); 
	res1 *= check(data[0], data[1], data[3]); 
	int res2=1;
	res2 *= check(data[2], data[3], data[0]); 
	res2 *= check(data[2], data[3], data[1]); 

	if( (res1 < 0)&&(res2 < 0) ) 
		std::cout << 1 << std::endl;	
	else if( res1*res2 == 0 )
		std::cout << 2 << std::endl;
	else 
		std::cout << 0 << std::endl;
	


}

void input_data(std::ifstream& fin , std::vector< std::pair<int, int> >& data)
{
	int coord_x, coord_y;
	for( int i=0; i<4; ++i)
	{
		fin >> coord_x >> coord_y;
		data.push_back( std::make_pair(coord_x, coord_y) );
	}
}

int check(const std::pair<int, int>& point_1, const std::pair<int, int>& point_2, const std::pair<int, int>& point_3)
{
	int ax = point_1.first;
	int ay = point_1.second;
	int bx = point_2.first;
	int by = point_2.second;
	int cx = point_3.first;
	int cy = point_3.second;

	int res;
	res = ( (bx - ax)*(cy - ay) - (cx - ax)*(by - ay) );

	if ( res > 0 ) 
		return 1;
	else if ( res < 0 ) 
		return -1;
	else	// if ( res == 0 )
		return 0;
}


