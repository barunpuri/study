#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

void IPv4(std::ifstream& fin);
void conv_IPadd_to_int(std::ifstream& fin);
unsigned int calc_IPadd(const std::vector<int>& address);
void conv_int_to_IPadd(std::ifstream& fin);

int main()
{
	std::ifstream	fin; 
	int		numTestCase;

	fin.open("input.txt");
	fin >> numTestCase;	
	for(int i=0; i<numTestCase; ++i)
		IPv4(fin);
	fin.close();
	
	return 0;
}	

void IPv4(std::ifstream& fin)
{	
	int type;
	
	fin >> type;
	
	if( type == 1)
		conv_IPadd_to_int(fin);
	else  //type == 2
		conv_int_to_IPadd(fin);
}

void conv_IPadd_to_int(std::ifstream& fin)
{
	std::vector<int> address;
	int IP1, IP2, IP3, IP4;
	char temp;
		
	fin >> IP1 >> temp >> IP2 >> temp >> IP3 >> temp >> IP4;
	address.push_back(IP1);
	address.push_back(IP2);
	address.push_back(IP3);
	address.push_back(IP4);

	unsigned int res = calc_IPadd(address);

	std::cout << res << std::endl;
}

unsigned int calc_IPadd(const std::vector<int>& address)
{
	unsigned int res =0;
	for(int i=0; i<address.size(); ++i)
	{
		res = res + address[address.size()-1-i]*pow( 2, (8*i) );
	}
	
	return res;
}

void conv_int_to_IPadd(std::ifstream& fin)
{
	unsigned int num;
	fin >> num;
	
	int IP1 = num/pow( 2, (8*3) );
	int IP2 = num%(int)pow( 2, (8*3) )/pow( 2, (8*2) );
	int IP3 = num%(int)pow( 2, (8*3) )%(int)pow( 2, (8*2) )/pow( 2, (8*1) );
	int IP4 = num%(int)pow( 2, (8*3) )%(int)pow( 2, (8*2) )%(int)pow( 2, (8*1) );

	std::cout << IP1 << "." << IP2 << "." << IP3 << "." << IP4 << std::endl;
}
