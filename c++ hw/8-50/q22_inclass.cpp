#include <iostream>
#include <vector>
#include <fstream>

void q22(std::ifstream& fin);
int count_prime_2(int number);
int count_prime_5(int number);
int update_last_num(int last_num, int num);

int main()
{	
	std::ifstream fin;
	int numTestCases;

	fin.open("input.txt");

	fin >> numTestCases;
	
	for(int i=0; i< numTestCases; ++i)
		q22(fin);

	fin.close();

	return 0;
}	

void q22(std::ifstream& fin) 
{
	std::vector<int> nums;

	int count;
	fin >> count;
	
	for(int i=0; i< count; ++i)
	{
		int num;
		fin >> num;
		nums.push_back(num);

	}
		
	int res;
	res = 1;
	int sum_cnt_2 = 0;
	int sum_cnt_5 = 0;
	int last_num = 1;
	for(int i=0; i<nums.size(); ++i)
	{
		sum_cnt_2 += count_prime_2(nums[i]);
		sum_cnt_5 += count_prime_5(nums[i]);

		last_num = update_last_num(last_num, nums[i]);

	}	
	
	int cnt_0 = sum_cnt_2 < sum_cnt_5 ? sum_cnt_2 : sum_cnt_5;
	//int cnt_0 = std::min(cnt_2, cnt_5);
	
	std::cout << last_num << " " << cnt_0 << std::endl;

}

int count_prime_2(int number)
{
	int cnt =0;
	while(number%2==0)
	{
		++cnt;
		number  /= 2 ;
	}
	return cnt;
}

int count_prime_5(int number)
{	
	int cnt =0;
	while(number%5==0)
	{
		++cnt;
		number  /= 5 ;
	}	
	
	return cnt;
}

int update_last_num(int last_num, int num)
{
	int res = last_num * num;
	while(res % 10 ==0)
		res/=10;
	
	res%=10;

	return res;
}


