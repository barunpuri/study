#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void bingo(std::ifstream& fin);
void input_data( std::ifstream& fin, std::vector<int>& field, std::vector<int>& nums);
int start_game(std::vector<int>& field, const std::vector<int>& nums);
bool check_bingo(const std::vector<int>& field);
bool check_line(const std::string& line, const std::vector<int>& field);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		bingo(fin);
	fin.close();

	return 0;
}

void bingo(std::ifstream& fin)
{
	std::vector<int> field, nums; 
	int cnt;
	input_data(fin, field, nums);

	cnt = start_game(field, nums);
	
	std::cout << cnt << std::endl;
	

}

void input_data( std::ifstream& fin, std::vector<int>& field, std::vector<int>& nums)
{
	int num;
	for( int i=0; i<5*5; ++i)
	{
		fin >> num;
		field.push_back(num);
	}
	
	for( int i=0; i<75; ++i)
	{		
		fin >> num;
		nums.push_back(num);
	}
}

int start_game(std::vector<int>& field, const std::vector<int>& nums)
{
	int cnt=0;
	while( true )
	{
		for(int i=0; i<field.size(); ++i)
		{
			if( field[i] == nums[cnt] )
				field[i] = 0;
		}

		cnt = cnt +1;
	
		if( check_bingo(field) )
			break;
	}

	return cnt;
	
}

bool check_bingo(const std::vector<int>& field)
{
	int cnt = 0; 
	cnt = cnt + field[0] + field[4] + field[20] + field[24];
	if( cnt == 0 )
		return true;
	else if( check_line("row", field)||check_line("col", field)||check_line("diag", field) )
		return true;
	else
		return false;
}

bool check_line(const std::string& line, const std::vector<int>& field)
{	
	int cnt;
	if( line == "row" ) 
	{
		for(int i=0; i<5; ++i)
		{	
			cnt = 0;
			cnt = cnt + field[i] + field[i+5] + field[i+10] + field[i+15] + field[i+20];
			if( cnt == 0 )
				return true;
		}
	}
	else if( line == "col" )
	{
		for(int i=0; i<5; ++i)
		{
			cnt = 0;
			cnt = cnt + field[i*5] + field[i*5+1] + field[i*5+2] + field[i*5+3] + field[i*5+4];
			if( cnt == 0 )
				return true;
		}
	}
	else	// if( line == "diag" )
	{
		cnt = 0;
		cnt = cnt + field[0] + field[6] + field[12] + field[18] + field[24];
		if( cnt == 0 )
			return true;

		cnt = 0;
		cnt = cnt + field[4] + field[8] + field[12] + field[16] + field[20];
		if( cnt == 0 )
			return true;
	}
	
	return false;
}


