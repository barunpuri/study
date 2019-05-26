#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

//thousand = 1,000 = pow(10,3)
//million = 1,000,000 = pow(10,6)
//billion = 1,000,000,000 = pow(10,9)

void reading_num(std::ifstream& fin, const std::string nums[], const std::string ties[], const std::string units[]);
std::vector<int> input_data(std::ifstream& fin);
void calc_res(const std::vector<int>& data, const std::string nums[], const std::string ties[], const std::string units[], std::vector<std::string>& res);
void under_100(int num, const std::string nums[], const std::string ties[], std::vector<std::string>& res);
void print(const std::vector<std::string>& res);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;

	std::string nums[20] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	std::string ties[10] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	std::string units[4] = { "", "Thousand", "Million", "Billion" };
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		reading_num(fin, nums, ties, units);
	fin.close();
	
	return 0;
}

void reading_num(std::ifstream& fin, const std::string nums[], const std::string ties[], const std::string units[])
{
	std::vector<int> data ;
	std::vector<std::string> res;

	data = input_data(fin);

	calc_res(data, nums, ties, units, res);

	print( res );


}

std::vector<int> input_data(std::ifstream& fin)
{
	std::string str;
	std::vector<int> data;
	int num;
	int cipher;
	int res=0;
	fin >> str;

	for(int i=0; i<str.size(); ++i)
	{	
		num = str[i]-48;
		cipher = str.size()-1-i;

		res += num * pow(10,cipher%3);

		if( cipher%3 ==0 ) 
		{
			data.push_back(res);	
			res=0;
		}		
	}

	return data;
}

void calc_res(const std::vector<int>& data, const std::string nums[], const std::string ties[], const std::string units[], std::vector<std::string>& res)
{
	int cipher;	//자릿수
	int num;

	for(int i=0; i<data.size(); ++i)
	{
		num = data[i];

		if( num == 0 )
			continue;
		
		if( num/100 >= 1 )
		{
			res.push_back( nums[num/100] );
			res.push_back( "Hundred" );

		}
		
		under_100( num%100, nums, ties, res);
		res.push_back( units[data.size()-1-i] );



	}
}



void under_100(int num, const std::string nums[], const std::string ties[], std::vector<std::string>& res)
{
	if( num < 20 )
	{
		res.push_back( nums[num] );	
	}
	else
	{
		res.push_back( ties[num/10] ); 
		res.push_back( nums[num%10] );
	}

}


void print(const std::vector<std::string>& res)
{
	std::cout << res[0] ;
	for(int i=1; i<res.size(); ++i)
	{
		if( res[i] == "" )
			continue;
		std::cout << "_" << res[i] ;
	}
	std::cout << std::endl;
}




