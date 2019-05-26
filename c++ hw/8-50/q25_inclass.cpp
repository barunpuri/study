#include <iostream>
#include <fstream>
#include <map>		//g++ -std=c++11 test.cpp 이렇게 컴파일
#include <vector>
#include <algorithm>

void q25(std::ifstream& fin);
void read_data(std::ifstream& fin, std::vector<int>& num, int numInts);
void make_dict(const std::vector<int>& num, std::map<int,int>& dict);
void print_dict(const std::map<int, int>& dict);

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
	std::vector<int> num;
	std::map<int, int> dict;

	int numInts;
	fin >> numInts;
	read_data(fin, num, numInts);
	make_dict(num, dict);

	print_dict(dict);

}

void read_data(std::ifstream& fin, std::vector<int>& num, int numInts)
{
	int data;
	for(int i=0; i<numInts; ++i)
	{
		fin >> data;
		num.push_back(data);
	}
	
}

void make_dict(const std::vector<int>& num, std::map<int, int>& dict)
{
	for(int i=0; i<num.size(); ++i)
	{
		std::map<int, int>::iterator it;
		it = dict.find(num[i]); // num[i] 가 dict 에 존재? -> 위치
		if( it == dict.end() ) // 없다
			dict[num[i]]=1;
		else
			dict[num[i]] += 1;
		
	}
}

void print_dict(const std::map<int, int>& dict)
{
	std::map<int, int>::const_iterator cit;
	sort(dict.cbegin(), dict.cend());
	for(cit=dict.cbegin(); cit!=dict.cend(); ++cit)
	{
		std::cout << "key : val" << cit->first << ":" << cit->second <<std::endl;
	}



}
