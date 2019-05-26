#include <iostream>
#include <fstream>
#include <set>

void q27(std::ifstream& fin);
void input_data(std::ifstream& fin, std::set<int>& set);
std::set<int> calc_intersect(const std::set<int>& set_A, const std::set<int>& set_B);
std::set<int> calc_union( std::set<int> set_A, const std::set<int>& set_B);
std::set<int> calc_diff(std::set<int> set_A, const std::set<int>& set_B);
void print(const std::set<int>& set);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q27(fin);
	fin.close();
	
	return 0;

}

void q27(std::ifstream& fin)
{
	std::set<int> A;
	std::set<int> B;

	input_data(fin, A);
	input_data(fin, B);	

	std::set<int> cap = calc_intersect(A, B);
	std::set<int> cup = calc_union(A, B);
	std::set<int> diff = calc_diff(A, B);

	print(cap);
	print(cup);
	print(diff);
}

void input_data(std::ifstream& fin, std::set<int>& set)
{
	int num_elem, data;
	fin >> num_elem;
	for(int i=0; i<num_elem; ++i)
	{
		fin >> data;
		set.insert(data);
	}
}

std::set<int> calc_intersect(const std::set<int>& set_A, const std::set<int>& set_B)
{
	std::set<int> res;
	for(std::set<int>::iterator it = set_A.begin(); it != set_A.end(); ++it)
	{
		if(set_B.find(*it) != set_B.end())
			res.insert(*it);
	}
	return res;
}

std::set<int> calc_union( std::set<int> set_A, const std::set<int>& set_B)
{
	for(std::set<int>::iterator it = set_B.begin(); it != set_B.end(); ++it)
	{
		set_A.insert(*it);
	}
	return set_A;
}

std::set<int> calc_diff(std::set<int> set_A, const std::set<int>& set_B)
{
	for(std::set<int>::iterator it = set_B.begin(); it != set_B.end(); ++it)
	{
		if(set_A.find(*it) != set_A.end())
			set_A.erase(set_A.find(*it));
	}
	return set_A;
}

void print(const std::set<int>& set)
{
	std::cout << set.size() << " ";
	for(std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
