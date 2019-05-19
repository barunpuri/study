#include <iostream>
#include <fstream>
#include <vector>
#include "lifegame.h"

lifegame::lifegame()
	:row_size_(0), col_size_(0), generation_(0)
	{
		field_.clear();	
	}
lifegame::lifegame(std::ifstream &fin)
	:row_size_(0), col_size_(0), generation_(0)
	{
		int data;
		fin >> row_size_ >> col_size_;
		input_data(fin);
	}
lifegame::lifegame(int row, int col, std::ifstream& fin)
	:row_size_(row), col_size_(col), generation_(0)
	{
		input_data(fin);
	}

int lifegame::getRow() const  { return row_size_; }
int lifegame::getCol() const  { return col_size_; }
int lifegame::getSize() const { return getRow()*getCol(); }
int lifegame::getGeneration() const { return generation_; }

void lifegame::input_data(std::ifstream& fin)
{
	char data;
	for(int i=0; i<getRow()*getCol(); ++i)
	{
		fin >> data;
		field_.push_back(data); 
	}
	
}
void lifegame::next()
{
	std::vector<int> coming;
	coming.clear();
	
	for(int i=0; i<getRow(); ++i)
	{	
		for(int j=0; j<getCol(); ++j)
		{
			coming.push_back( update(i,j) );
		}
	}
	for(int i=0; i<getSize(); ++i)
		field_[i] = coming[i];

	++generation_;
	
}

char lifegame::update(int i, int j)
{
	int cnt ;
	cnt = count_close_cells(i, j);
	
	if( cnt == 3 )
		return 'O';	
	else if( (field_[i*getCol() + j] == 'O')&&(cnt==2) )
		return 'O';
	else 
		return 'X';
	
}

int lifegame::count_close_cells(int x, int y)
{
	int cnt = 0;
	int x_dir[8] = {-1,-1,0,1,1,1,0,-1};
	int y_dir[8] = {0,1,1,1,0,-1,-1,-1};
	int x_loc;
	int y_loc;
	
	for(int i=0; i<8; ++i)
	{
		x_loc = x+x_dir[i];
		y_loc = y+y_dir[i];

		if( ( (x%getRow()==0)&&(x_dir[i]==-1) )
		||( (x%getRow()==getRow()-1)&&(x_dir[i]==1) )
		||( (y%getCol()==0)&&(y_dir[i]==-1) )
		||( (y%getCol()==getCol()-1)&&(y_dir[i]==1) ) )
			continue;
	
		
		if( field_[x_loc*getCol() + y_loc] == 'O')
			++cnt;
	}

	return cnt;
}
int lifegame::count_living_cells()
{
	int cnt=0;
	for(int i=0; i<getSize(); ++i)
		if( field_[i] == 'O' )
			cnt += 1;

	return cnt;
}


char lifegame::operator() (unsigned int row, unsigned int col) const
{
	return field_[row*getCol() + col];
}

char& lifegame::operator() (unsigned int row, unsigned int col)
{
	return field_[row*getCol() + col];
}

int lifegame::color(int i, int j){
	std::vector<bool> visited(getSize(), false);

	int cnt =0;

	if( field_[i*getCol() + j] == 'O' )
	{
		visited[i*getCol() + j] = true;
		cnt = cnt_color(i,j, visited);
	}
	return cnt;
}
	
int lifegame::cnt_color(int x, int y, std::vector<bool>& visited)
{
	int x_loc;
	int y_loc;
	int x_dir[8] = {-1,-1,0,1,1,1,0,-1};
	int y_dir[8] = {0,1,1,1,0,-1,-1,-1};
	int cnt = 1;	//자기자신

	for(int i=0; i<8; ++i)
	{
		x_loc = x+x_dir[i];
		y_loc = y+y_dir[i];
		if( ( (x%getRow()==0)&&(x_dir[i]==-1) )
		||( (x%getRow()==getRow()-1)&&(x_dir[i]==1) )
		||( (y%getCol()==0)&&(y_dir[i]==-1) )
		||( (y%getCol()==getCol()-1)&&(y_dir[i]==1) ) )
			continue;
		
		if( visited[x_loc*getCol() + y_loc] ==false &&
			 field_[x_loc*getCol() + y_loc] == 'O')
		{
			visited[x_loc*getCol() + y_loc] = true;
			cnt += cnt_color(x_loc, y_loc, visited);
		}
	}

	return cnt;	
}
	
	
	
	
	
	
	


