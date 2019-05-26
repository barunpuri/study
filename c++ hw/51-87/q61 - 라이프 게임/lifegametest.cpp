#include <iostream>
#include <fstream>
#include <vector>


class lifegame
{
private:
	int row_;
	int col_;
	std::vector<char> data;
public:
	lifegame()
		: row_(0), col_(0)
	{}
	lifegame(int row, int col) 
		: row_(row), col_(col)
	{
		data.clear();
		data.assign((row+2)*(col+2), 'X');
	}
	int getRow() const
	{
		return row_ ;
	}
	int getCol() const
	{
		return col_ ;
	}
	int getSize() const
	{
		return (getRow()+2)*(getCol()+2);
	}
	void passing()
	{
		
	}	
	void passing(int times)
	{
		for(int i=0; i<times; ++i)
		{
			passing();
		}
	}
	char& operator() (unsigned int r, unsigned int c)
	{
		return data[r*getCol() + c];
	}
	char operator() (unsigned int r, unsigned int c) const
	{
		return data[r*getCol() + c];
	}

};


std::ostream& operator<< (std::ostream& os, const lifegame& cell)
{


	for( unsigned int r=1; r<=cell.getRow(); ++r)
	{
		for( unsigned int c=1; c<=cell.getCol(); ++c)
		{	
			os << A(r,c) <<" ";
		}

	os << std::endl;
	}

	return os;
} 




int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		life_game(fin);
	fin.close();
	
	return 0;

}

void life_game(std::ifstream& fin)
{
	int row, col, generations;
	fin >> row >> col >> generations;

	lifegame cell(row, col);

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			 fin >> cell(row+1, col+1) ;
	
	cell.passing(generations);
	
	std::cout << cell ;
		

}
