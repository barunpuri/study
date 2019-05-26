#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void cross_puzzle(std::ifstream& fin);
void input_data(std::ifstream& fin, int row, int col, std::vector<char>& grid);
void check_letter(const std::string& str, int col, const std::vector<char>& grid);
int cnt_right_letter(const std::string& str, int loc, int change, const std::vector<char>& grid );

int main()
{
	std::ifstream	fin;
	int		numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		cross_puzzle(fin);
	fin.close();

	return 0;
}

void cross_puzzle(std::ifstream& fin)
{
	int row, col, numStr;
	std::vector<char> grid;

	fin >> row >> col;
	input_data(fin, row+1, col+1, grid);
	fin >> numStr;

	std::string str;
	for(int i=0; i<numStr; ++i)
	{
		fin >> str;
		check_letter(str, col+2, grid);
	}

}

void input_data(std::ifstream& fin, int row, int col, std::vector<char>& grid)
{
	std::string str;
	char letter;
	for(int i=0; i<=row; ++i)
	{
		for(int j=0; j<=col; ++j)
		{
			if( (i==0)||(i==row)||(j==0)||(j==col) )
			{
				grid.push_back(' ');
			}
			else
			{
				fin >> letter;
				grid.push_back(letter);
			}
		}
	}
}

void check_letter(const std::string& str, int col, const std::vector<char>& grid)
{
	//int dir[8][2] = { [[-col, 0], [-col,1], [0,1], [col,1], [col,0], [col,-1], [0,-1], [-col,-1]] };
	int dir[8] = { -col+0, -col+1, 0+1, col+1, col+0, col-1, 0-1, -col-1 };
	int i;
	int way; 
	bool done = false;
	for(i=0; i<grid.size()-col; ++i)
	{
		if( grid[i] == ' ' ) 
			continue;
			
		if( grid[i] == str[0] )
		{
			for(way=0; way<8; ++way)
			{
				//int change = dir[i][1] + dir[i][2];
				if( cnt_right_letter(str, i, dir[way], grid) == str.size() )
				{
					done = true;
					break;
				}	
			}
		}

		if(done) 
			break;
	}

	if(done)
		std::cout << (int)(i/col) << " " << i%col << " " << way << std::endl;
	else 
		std::cout << -1 << std::endl;
}

int cnt_right_letter(const std::string& str, int loc, int change, const std::vector<char>& grid )
{
	int cnt=1;

	for(int i=1; i<str.size(); ++i)
	{
		if( str[i] == grid[loc+i*change] )
			++cnt; 
	
//		std::cout << str[i] << grid[loc+i*change]<< " ";
	}

	return cnt;
}
