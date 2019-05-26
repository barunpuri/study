#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void q44(std::ifstream& fin);
void calc(char bracket, std::vector<char>& brackets);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q44(fin);
	fin.close();
	
	return 0;
}

void q44(std::ifstream& fin)
{
	std::vector<char> brackets;
	std::string temp;
	fin >> temp;

	for(int i=0; i<temp.size(); ++i)
		calc(temp[i], brackets);	
	
	if(brackets.size() == 0 )
		std::cout << "1" << std::endl;
	else
		std::cout << '0' << std::endl;
}

void calc(char bracket, std::vector<char>& brackets)
{
	if( (bracket == ')')&&( brackets[brackets.size()-1] == '(' ) )
		brackets.erase(brackets.end()-1);
	else if( (bracket == '}')&&( brackets[brackets.size()-1] == '{' ) )
		brackets.erase(brackets.end()-1);
	else if( (bracket == ']')&&( brackets[brackets.size()-1] == '[' ) )
		brackets.erase(brackets.end()-1);
	else
		brackets.push_back(bracket);
}






