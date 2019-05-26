#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void q40(std::ifstream& fin);
void input_data(std::ifstream& fin, std::vector<char>& letters, std::vector<int>& nums);
void det(std::vector<char> letters, std::vector<int> nums);
bool is_straight(std::vector<int> nums);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q40(fin);
	fin.close();
	
	return 0;

}

void q40(std::ifstream& fin)
{
	std::vector<char> letters;
	std::vector<int> nums;

	input_data(fin, letters, nums);

	sort( letters.begin(), letters.end() );
	sort( nums.begin(), nums.end() );
	
	det(letters, nums);
}

void input_data(std::ifstream& fin, std::vector<char>& letters, std::vector<int>& nums)
{
	char data;
	int num;
	for(int i=0; i<5; i++)
	{
		fin >> data;
		if( ( 97 <= (int)data )&&( (int)data <= 122) )//소문자 ->대문자
			data = (int)data - 32;
		letters.push_back((char)data);
		
		fin >> data;
		if(data == 'A') 	//문자 ->숫자
			num = 1; 	//ASCII int 49 = char 1
		else if(data == 'T')
			num = 10;
		else if(data == 'J')
			num = 11;
		else if(data == 'Q')
			num = 12;
		else if(data == 'K')
			num = 13;
		else if( (50<=data)||(data<=57) )
			num = (int)data -48;
		nums.push_back(num);

	}
}


void det(std::vector<char> letters, std::vector<int> nums)
{
	if( letters[0] == letters[4] )
	{
		if( is_straight(nums) )
			if(nums[0]==1)
				std::cout << "Royal_Flush" << std::endl;
			else
				std::cout << "Straight_Flush" << std::endl;
		else
			std::cout << "Flush" << std::endl;
	}
	else if( is_straight(nums) )
		std::cout << "Straight" << std::endl;
	else if(nums[0] == nums[3] || nums[1] == nums[4])
		std::cout << "Four_of_a_Kind" << std::endl;
	else if( (nums[0]==nums[2])||(nums[2]==nums[4]) )
	{
		if( ( (nums[2]==nums[4])&&(nums[0]==nums[1]) )
		||( (nums[0]==nums[2])&&(nums[3]==nums[4]) ) )
			std::cout << "Full_House" << std::endl;
		else
			std::cout << "Three_of_a_kind" << std::endl;
	}
	else if( (nums[0]==nums[1]&&nums[2]==nums[3])
		||(nums[0]==nums[1]&&nums[3]==nums[4])
		||(nums[1]==nums[2]&&nums[3]==nums[4]) )
		std::cout << "Two_Pairs" << std::endl;
	else if( (nums[0]==nums[1])||(nums[1]==nums[2])
		||(nums[2]==nums[3])||(nums[3]==nums[4]) )
		std::cout << "Pair" << std::endl;
	
	else 
		std::cout << "High_Cards" << std::endl;
}

bool is_straight(std::vector<int> nums)
{
	bool res=true;

	if( (nums[0]==1) && (nums[1]==10) && (nums[2]==11) 
	&& (nums[3]==12) &&  (nums[4]==13) )		// A, T, J, Q, K
		return res;


	for(int i=0; i<nums.size()-1; ++i)
	{
		if(nums[i+1]-nums[i]!=1)		
		{
			res = false;
			break;
		}
	}	
	return res;
}












