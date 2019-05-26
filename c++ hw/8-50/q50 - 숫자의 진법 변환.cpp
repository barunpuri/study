#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

void q50(std::ifstream& fin);
void change_notation(std::vector<char>& afterNum, int num, int notationTo);
void print(const std::vector<char>& afterNum);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q50(fin);
	fin.close();
	
	return 0;
}

void q50(std::ifstream& fin)
{
	int notationFrom, notationTo;
	std::string earlyNum;
	std::vector<char> afterNum;	
	int num=0;
	int coef, expo;
	
	fin >> notationFrom >> earlyNum >> notationTo;

	for(int i=0; i< earlyNum.size(); ++i)
	{	
		coef = earlyNum[i];
		expo = earlyNum.size()-1-i;

		if( coef >= 'a' )
			coef = coef-87; 
		else
			coef = coef-48;
	
		num = num + (coef) * pow(notationFrom, expo) ; 	//string 에 int를 넣으면 아스키코드를 따른다?
	}

	change_notation(afterNum, num, notationTo);

	print(afterNum);

}

void change_notation(std::vector<char>& afterNum, int num, int notationTo)
{
	int temp=0;
	while( true )
	{
		if(pow(notationTo,temp+1) > num ) 	
			break;
		++temp;
	}

	int tempNum;
	for(int i=0; i<=temp; ++i)
	{
		tempNum = num/pow(notationTo, temp-i);
		if(tempNum >= 10)
			afterNum.push_back( tempNum+39 );
		else
			afterNum.push_back( tempNum );
		num = num - tempNum*pow(notationTo, temp-i);
	}
}

void print(const std::vector<char>& afterNum)
{
	for(int i=0; i<afterNum.size(); ++i)
		std::cout << (char)(afterNum[i]+48);

	std::cout << std::endl;
}
