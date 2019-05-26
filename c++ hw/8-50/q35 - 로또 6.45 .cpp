#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void q35(std::ifstream& fin);
void inputData(std::ifstream& fin, std::vector<int>& win_case, std::vector<int>& test_case, int& bonus_num);
int get_match_num(std::vector<int> win_case, std::vector<int> test_case);
int calc_grade(int num_matched, std::vector<int> test_case, int bonus_num);


int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q35(fin);
	fin.close();
	
	return 0;

}

void q35(std::ifstream& fin)
{
	std::vector<int> win_case;
	std::vector<int> test_case;
	int bonus_num;
	
	inputData(fin, win_case, test_case, bonus_num);

	sort( win_case.begin(), win_case.end() );
	sort( test_case.begin(), test_case.end() );
	
	int num_matched;
	num_matched = get_match_num(win_case, test_case);	

	int res;
	res = calc_grade(num_matched, test_case, bonus_num);
	
	std::cout << res << std::endl;

}

void inputData(std::ifstream& fin, std::vector<int>& win_case, std::vector<int>& test_case, int& bonus_num)
{
	int data;
	for(int i=0; i<6; ++i)
	{
		fin >> data;
		win_case.push_back(data);
	}

	fin >> bonus_num;

	for(int i=0; i<6; ++i)
	{
		fin >> data;
		test_case.push_back(data);
	}
}

int get_match_num(std::vector<int> win_case, std::vector<int> test_case)
{
	int res=0;
	for(int i=res; i<win_case.size(); ++i)
	{
		for(int j=res; j<test_case.size(); ++j)
		{
			if(test_case[j] == win_case[i])
			{
				res += 1;
				break;
			}
		}
	}	
	return res;
}

int calc_grade(int num_matched, std::vector<int> test_case, int bonus_num)
{
	int res;
	if(num_matched ==6)
		res =1;
	else if( num_matched==5 )
	{	
		res = 3;
		for(int i=0; i<test_case.size(); ++i)
		{
			if(test_case[i] == bonus_num)
			{
				res = 2;
				break;
			}
		}
	}
	
	else if( num_matched == 4 )
		res = 4;
	else if( num_matched == 3 )
		res = 5;
	else 
		res = 0;
	
	return res;
}





