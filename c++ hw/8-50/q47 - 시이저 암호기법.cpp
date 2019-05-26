#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void q47(std::ifstream& fin);
void encrypt(std::vector<char>& letters, int code);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q47(fin);
	fin.close();
	
	return 0;
}

void q47(std::ifstream& fin)
{
	std::vector<char> letters;
	
	int code;
	std::string temp;
	fin >> code;
	fin >> temp;
	for(int i=0; i<temp.size(); ++i)
		letters.push_back(temp[i]);
	
	encrypt(letters, code);

	for(int i=0; i<letters.size(); ++i)
		std::cout << letters[i] ;
	std::cout << std::endl;

}

void encrypt(std::vector<char>& letters, int code)
{
	for(int i=0; i<letters.size(); ++i)
	{
		if( (65 <= letters[i])&&(letters[i] <= 90) )
		{
			letters[i] = (int)letters[i] + code;
			if( 91 <= (int)letters[i])
				letters[i] = (int)letters[i] - 26;
		}
		else if( (97 <= letters[i])&&(letters[i] <= 122) )
		{
			letters[i] = (int)letters[i] - 26 + code;
			if( (int)letters[i] <= 96)
				letters[i] = (int)letters[i] + 26;
		}
	}
}

