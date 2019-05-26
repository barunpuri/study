#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void q25(std::ifstream& fin);
void count(std::vector<int>& nums, std::vector<int>& count_nums);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q25(fin);
	fin.close();
	
	return 0;

}

void q25(std::ifstream& fin)
{
	std::vector<int> nums;
	std::vector<int> count_nums;

	int numInts, data;
	fin >> numInts;
	for(int i=0; i<numInts; ++i)
	{
		fin >> data;
		nums.push_back(data);
	}	

	sort( nums.begin(), nums.end() );			
	
	count(nums, count_nums);

	int num_mode = *std::max_element(count_nums.begin(), count_nums.end());
	for(int i=0; i<nums.size(); ++i)
	{
		if(num_mode > count_nums[i])
		{	
			count_nums.erase(count_nums.begin()+i);
			nums.erase(nums.begin()+i);
			--i;
		}	
	}

	std::cout << nums.size() << " " << num_mode << " ";
	
	for(int i=0; i<nums.size(); ++i)
		std::cout << nums[i] << " " ;
	std::cout  << std::endl;
	
}	

void count(std::vector<int>& nums, std::vector<int>& count_nums)
{	
	int temp=1;
	for(int i=0; i<nums.size(); i)
	{	
		if( i==nums.size()-1 )
		{	
			count_nums.push_back(temp);
			break;
		}
		if(nums[i]==nums[i+1])
		{
			nums.erase(nums.begin()+i+1);
			temp += 1;
		}
		else
		{
			count_nums.push_back(temp);		
			temp = 1;
			++i;
		}
	}
}




