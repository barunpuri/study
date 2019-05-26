#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void q46(std::ifstream& fin);
bool seperator_e_part(const std::string& _str, std::string& _p1, std::string& _p2);
bool seperator_dot_part(const std::string& _str, std::string& _p1, std::string& _p2);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q46(fin);
	fin.close();
	
	return 0;
}

void q46(std::ifstream& fin)
{
	std::string temp;
	fin >> temp;

	std::string before_e, after_e;
	std::string before_dot, after_dot;
	bool res;
	
	seperator_e_part(temp, before_e, after_e); 
	seperator_dot_part(before_e, before_dot, after_dot);
	
	unsignedint dot_cnt=0;
	for(int i=0; i<before_e.size(); ++i)
	{
		char ch = before_e[i];
		if( ch < '.')
			res = false;
	}
	for(int i=0;


}

