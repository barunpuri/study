#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void q46(std::ifstream& fin);
int input_data(std::ifstream& fin, std::vector<char>& data, int& coordDot, int& coordE);
int det_res(const std::vector<char>& data, const int& coordDot, const int& coordE);
bool is_int(const char& num);


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
	std::vector<char> data;
	int coordDot = -1;
	int coordE = -1;
	int res;

	res = input_data(fin, data, coordDot, coordE);
//std::cout <<res << " ";
	if(res != 0)
		res = det_res(data, coordDot, coordE);

	std::cout << res << std::endl;

}

int input_data(std::ifstream& fin, std::vector<char>& data, int& coordDot, int& coordE)
{
	std::string temp;
	fin >> temp;

	for(int i=0; i<temp.size(); ++i)
	{
		if(temp[i] == '.')	//.의 위치 저장 
			if(coordDot != -1)	//. 2개 이상 -> 0 출력 
				return 0;
			else
				coordDot = i;
		if( (temp[i] == 'e')||(temp[i] == 'E') ) //e의 위치 저장
			if(coordE != -1)		//e 2개 이상 -> 0출력
				return 0;
			else
				coordE = i;
			
		data.push_back(temp[i]);	
	}

	if( coordE == -1 )
	{
		if( coordDot == -1)		//e,.두개 모두 없을때
			return 0;
		coordE = data.size();
	}
	
	return 1;
}

int det_res(const std::vector<char>& data, const int& coordDot, const int& coordE)
{
	if( (coordE <= coordDot)||(coordE+1 == data.size()) )
		return 0;
	int cnt = 0;
	for( int i=0; i<coordE; ++i)
	{
		if( (i == coordDot)&&(data.size() !=1) )
			continue;
		else if( !is_int(data[i])||(++cnt==-1) )
			return 0;
	}
	if( cnt == 0)
		return 0;

	if( ((data[coordE+1]=='+')||(data[coordE+1]== '-'))&&(data.size()-coordE == 2) )
		return 0;
//std::cout << data.size() << " " << coordE << " ";
	else if( (data[coordE+1]=='+')||(data[coordE+1]== '-')&&(data.size()-coordE != 2) )
	{
		for( int i=coordE+2; i<data.size(); ++i)
			if( is_int(data[i]) )
				continue;
			else
				return 0;
	} 
	else
	{
		for( int i=coordE+1; i<data.size(); ++i)
			if( is_int(data[i]) ) 
				continue;
			else
				return 0;
	}

/*	for( int i=coordE+1; i<data.size(); ++i)
	{
		if( (data[coordE+1]=='+')||(data[coordE+1]== '-')||( is_int(data[i]) ) )
			continue;
		else 
			return 0;
	
	} 
*/
	return 1;
}

bool is_int(const char& num)
{
	int integer = num - 48;

	if( (0<=integer)&&(integer<10) )
		return true;
	
	return false;
	
}












