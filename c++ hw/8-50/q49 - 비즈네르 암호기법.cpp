#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void q49(std::ifstream& fin);
void calc(std::vector<char> codes, std::vector<char>& letters, int is_encrypt);
void encrypt(std::vector<char> codes, std::vector<char>& letters);
void decrypt(std::vector<char> codes, std::vector<char>& letters);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q49(fin);
	fin.close();
	
	return 0;
}

void q49(std::ifstream& fin)
{
	std::vector<char> letters, codes;

	std::string temp;
	int is_encrypt;
	fin >> temp;
	for(int i=0; i<temp.size(); ++i)
	{
		codes.push_back(temp[i]);
		if( (int)codes[i]>90 )
			codes[i] = (int)codes[i] - 32; 	
	}
	fin >> is_encrypt;
	fin >> temp;
	for(int i=0; i<temp.size(); ++i)
		letters.push_back(temp[i]);
	

	calc(codes, letters, is_encrypt);

	for(int i=0; i<letters.size(); ++i)
		std::cout << letters[i];
	std::cout << std::endl;

}

void calc(std::vector<char> codes, std::vector<char>& letters, int is_encrypt)
{
	if(is_encrypt==1)
		encrypt(codes, letters);
	else
		decrypt(codes, letters);			
	
}

void encrypt(std::vector<char> codes, std::vector<char>& letters)
{
	int i=0, j=0;
	for(int i=0; i<letters.size(); ++i)
	{
		if( (65 <= letters[i])&&(letters[i] <=90) )
		{	
			letters[i] = (letters[i] - 65 + codes[i%codes.size()] - 65)%26 + 65;
		}
		else if( (97 <= letters[i])&&(letters[i] <= 122) )
		{	
			letters[i] = (letters[i] - 97 + codes[i%codes.size()] - 65)%26 + 97;
		}
	}
}

void decrypt(std::vector<char> codes, std::vector<char>& letters)
{
	int i=0, j=0;
	for(int i=0; i<letters.size(); ++i)
	{
		if( (65 <= letters[i])&&(letters[i] <=90) )
		{		
			letters[i] = (letters[i] - 65 - (codes[i%codes.size()] - 65) + 26)%26 + 65;
		}
		else if( (97 <= letters[i])&&(letters[i] <= 122) )
		{		
			letters[i] = (letters[i] - 97 - (codes[i%codes.size()] - 65) + 26)%26 + 97;
		}	
	}
}

