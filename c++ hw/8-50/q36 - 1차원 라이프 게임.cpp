#include <iostream>
#include <fstream>
#include <vector>

void q36(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<int>& cells, int numCells);
void progress(std::vector<int>& current,int times);
int update(std::vector<int>& cells, int loc);
int calc(int around);
void outputData(std::vector<int>& cells);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q36(fin);
	fin.close();
	
	return 0;

}

void q36(std::ifstream& fin)
{	
	int numCells;
	int times=0;
	fin >> numCells >> times;

	std::vector<int> cells;

	inputData(fin, cells, numCells);

	progress(cells, times);
	
	outputData(cells);
}

void inputData(std::ifstream& fin, std::vector<int>& cells, int numCells)
{
	int cell;
	for(int i=0; i<numCells; ++i)
	{
		fin >> cell;
		cells.push_back(cell);
	}
}

void progress(std::vector<int>& current,int times)
{
	std::vector<int> coming;
	for(int i=0; i<times; ++i)
	{	coming.clear();
		for(int j=0; j<current.size(); ++j)
		{	
			coming.push_back( current[j] + update(current, j) );
			if(coming[j]==-1)
				coming[j]=0;
			else if(coming[j]==10)
				coming[j]=9;
		}
		for(int j=0; j<coming.size(); ++j)
			current[j] = coming[j];
	}
}

int update(std::vector<int>& cells, int loc)
{
	
	if(loc==0)
		return calc( cells[loc+1]  );
	else if(loc==cells.size()-1 )
		return calc( cells[loc-1] );
	else 
		return calc( cells[loc-1] + cells[loc+1] );
}

int calc(int around)
{
	if( around == 3) 
		return 0;
	else if( (4<=around)&&(around<=7) )
		return 1;
	else 
		return -1;
}


void outputData(std::vector<int>& cells)
{
	for(int i=0; i<cells.size(); ++i)
		std::cout << cells[i] << " ";
	
	std::cout << std::endl;
}


