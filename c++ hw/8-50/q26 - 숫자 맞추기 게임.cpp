#include <iostream>
#include <fstream>
#include <string>

void q26(std::ifstream& fin);

void change_data_type(int output[], int input);
void cnt_strike(int temp[], int num_arr[], int& temp_s);
void cnt_ball(int temp[], int num_arr[], int& temp_b);
int cnt_num_true(const bool cases[], int& true_coord);
void print(int num_true, int true_coord);

int main()
{
	std::ifstream	fin;
	int 		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q26(fin);

	fin.close();

	return 0;

}

void q26(std::ifstream& fin)
{
	int input_nums;
	fin >> input_nums;

	int temp[4] ;
	int num_arr[4] ;
	int num, s, b, temp_s, temp_b;
	

	bool cases[10000] ;

	for( int i=0; i<10000; ++i)
		cases[i] = true;


	for( int i=0; i<input_nums; ++i)
	{
		fin >> num >> s >> b;

		for( int testNum=0; testNum<10000; ++testNum)
		{	
			if(cases[testNum] == false)
				continue;

			temp_s=0, temp_b=0;	
			
			change_data_type(temp, testNum);
			change_data_type(num_arr, num);

			cnt_strike( temp, num_arr, temp_s );	
			cnt_ball( temp, num_arr, temp_b );

//std::cout << temp_s<< " " << temp_b<< std::endl;

			if( (temp_s != s)||(temp_b != b) )
				cases[testNum] = false;
	
		}	
	}

	int num_true, true_coord;
	num_true = cnt_num_true(cases, true_coord);
	
	print(num_true, true_coord);

}

void change_data_type(int output[], int input)
{
	output[0] = input/1000;
	output[1] = input%1000/100;
	output[2] = input%1000%100/10;
	output[3] = input%1000%100%10;
} 

void cnt_strike(int temp[], int num_arr[], int& temp_s)
{
	for(int i=0; i<4; ++i)//s 개수
	{	
		if( temp[i] == num_arr[i] )
		{
			++temp_s;
			temp[i] = -2;
			num_arr[i] = -1;			
		}
	}

}

void cnt_ball(int temp[], int num_arr[], int& temp_b)
{
	for(int i=0; i<4; ++i)//b 개수 
	{	
		for(int j=0; j<4; ++j)
		{
			if( temp[i] == num_arr[j] )
			{
				++temp_b;
				temp[i] = -2;
				num_arr[j] = -1;
			}
		}		
	}
}


int cnt_num_true(const bool cases[], int& true_coord)
{
	int num_true =0;
	for(int i=0; i<10000; ++i)
	{	
		if( cases[i] == true)
		{	
			num_true++;
			true_coord = i;
		}
	}

	return num_true;
}

void print(int num_true, int true_coord)
{
	if( num_true ==1)
		std::cout << true_coord  << std::endl;
	else if( num_true == 0)
		std::cout << -2 << std::endl;
	else
		std::cout << -1 << std::endl;
}
