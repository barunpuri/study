#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

void q28(std::ifstream& fin);
unsigned int get_num_of_index(std::set<unsigned int>& hamming_num, int index);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q28(fin);
	fin.close();
	
	return 0;

}

void q28(std::ifstream& fin)
{
	int index;
	fin >> index;

	std::set<unsigned int> hamming_num;
	hamming_num.insert(1);

	unsigned int res;
	
	res = get_num_of_index(hamming_num, index-1);

	std::cout << res << std::endl;
}

unsigned int get_num_of_index(std::set<unsigned int>& hamming_num, int index)
{

	while( index>=hamming_num.size() )
	{
		for(std::set<unsigned int>::iterator i = hamming_num.begin(); i != hamming_num.end(); ++i)
		{
			if( *i >= 400000000)
				break;
			hamming_num.insert(*i*2);
			hamming_num.insert(*i*3);
			hamming_num.insert(*i*5);
		}
	}
	
	std::set<unsigned int>::iterator it = hamming_num.begin();
	for(int i=0; i<index; ++i)
		it++;

	return *it;


}

