#include <iostream>
#include <fstream>
#include <vector>

void life_game(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<char>& cells, int row, int col);
void progress(std::vector<char>& current, int generations, int row, int col);
char update(const std::vector<char>& cells, int i, int j, int col);
int count_close_cells(const std::vector<char>& cells, int i, int j, int col);
void outputData(const std::vector<char> cells, int row, int col);

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

	row += 2;
	col += 2;
	std::vector<char> cells;

	inputData(fin, cells, row, col);//태두리 : X
	
	progress(cells, generations, row, col);

	outputData(cells, row, col);	
}

void inputData(std::ifstream& fin, std::vector<char>& cells, int row, int col)
{
	char situ;
	for(int i=0; i<row; ++i)
	{	
		for( int j=0; j<col; ++j)
		{
			if( (i==0)||(i==row-1)||(j==0)||(j==col-1) )
			{
				cells.push_back('X');
				continue;
			}
			fin >> situ;
			cells.push_back(situ);
		}
	}
}

void progress(std::vector<char>& current, int generations, int row, int col)
{
	std::vector<int> coming;
	for(int i=0; i<generations; ++i)
	{	
		coming.clear();
	
		for(int j=0; j<row; ++j)
		{	
			for(int k=0; k<col; ++k)
			{
				if( (j==0)||(j==row-1)||(k==0)||(k==col-1) )
				{
					coming.push_back('X');
					continue;
				}
				coming.push_back( update(current,j,k,col) );
			}
		}
		for(int j=0; j<row*col; ++j)
			current[j] = coming[j];
	}
}

char update(const std::vector<char>& cells, int i, int j, int col)
{
	int cnt ;
	cnt = count_close_cells(cells, i, j, col);
	
	if( cnt == 3 )
		return 'O';	
	else if( (cells[i*col + j] == 'O')&&(cnt==2) )
		return 'O';
	else 
		return 'X';
	
}

int count_close_cells(const std::vector<char>& cells, int i, int j, int col)
{
	int cnt = 0;
	if( cells[(i-1)*col + j] == 'O') ++cnt;		// N
	if( cells[(i-1)*col + j+1] == 'O') ++cnt;	// NE
	if( cells[i*col + j+1] == 'O') ++cnt;		// E
	if( cells[(i+1)*col + j+1] == 'O') ++cnt;	// SE
	if( cells[(i+1)*col + j] == 'O') ++cnt;		// S
	if( cells[(i+1)*col + j-1] == 'O') ++cnt;	// SW
	if( cells[i*col + j-1] == 'O') ++cnt;		// W
	if( cells[(i-1)*col + j-1] == 'O') ++cnt;	// NW

	return cnt;
}

void outputData(const std::vector<char> cells, int row, int col)
{	
	int numCells = 0;
	for(int i=0; i<row*col; ++i)
	{
		if(cells[i]== 'O')
			numCells += 1;
	}

	std::cout << numCells << std::endl;

	for(int i=0; i<row; ++i)
	{
		if( (i==0)||(i==row-1) )
			continue;

		for(int j=0; j<col; ++j)
		{
			if( (j==0)||(j==col-1) )
				continue;
			std::cout << cells[i*col + j] ;
		}		
		std::cout << std::endl;
	}
}


