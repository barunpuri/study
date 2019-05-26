#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void morse_code(std::ifstream& fin, const std::string solution[], const std::string alphabet[]);
void input(std::ifstream& fin, std::vector<std::string>& code, const std::string solution[], const std::string alphabet[]);
std::string decode(const std::vector<std::string>& code, const std::string solution[], const std::string alphabet[]);


int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	const std::string solution[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	const std::string alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		morse_code(fin, solution, alphabet);
	fin.close();
		
	return 0;

}

void morse_code(std::ifstream& fin, const std::string solution[], const std::string alphabet[])
{
	std::vector<std::string> code;
	std::string res;

	input(fin, code, solution, alphabet);

	res = decode(code, solution, alphabet);

	std::cout << res << std::endl;

}

void input(std::ifstream& fin, std::vector<std::string>& code, const std::string solution[], const std::string alphabet[])
{
	std::string data;
	fin >> data;
	
	std::string str;
	std::string part = "";
	
	for(int i=0; i<data.size(); ++i)
	{
		str = data[i];
		if( (str == "|")||(str == "#") )
		{
			code.push_back(part);
			code.push_back(str);
			part = "";
			continue;
		}
		part.append(str);
	}
	code.push_back(part);
}

std::string decode(const std::vector<std::string>& code, const std::string solution[], const std::string alphabet[])
{
	std::string res = "";
	std::string str;

	

	for(int i=0; i<code.size(); ++i)
	{
		str = code[i];
		if( str == "|" )
			continue;
		else if(str == "#") 
		{
			res.append("_");
			continue;
		}

		for(int j=0; j<26; ++j)
		{
			if( solution[j] == str )
			{
				res.append(alphabet[j]);
				continue;
			}
		}
	}

	return res;
}













