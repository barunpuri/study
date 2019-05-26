#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void q48(std::ifstream& fin);
int cnt_alphabet(std::vector<char>& code, int num_each_alphabet[]);
void calc_freq(std::vector<float>& each_freq, int num_each_alphabet[], int num_alphabets);
int calc_kaiSquare(const std::vector<float>& each_freq);
void decrypt(std::vector<char>& code, int key);
void print(const std::vector<char>& code);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q48(fin);
	fin.close();
	
	return 0;
}

void q48(std::ifstream& fin)
{
	std::string data;
	fin >> data;
	std::vector<char> code;
	std::vector<float> each_freq;
	int num_each_alphabet[26] = {0,};
	int num_alphabets, max_freq;

	for(int i=0; i<data.size(); ++i)
		code.push_back(data[i]);

	num_alphabets = cnt_alphabet(code, num_each_alphabet);		
	
	calc_freq(each_freq, num_each_alphabet, num_alphabets);

	int key = calc_kaiSquare(each_freq);	

	decrypt(code, key);
	
	print(code);
}

int cnt_alphabet(std::vector<char>& code, int num_each_alphabet[])
{
	int cnt = 0;
	
	for(int i=0; i<code.size(); ++i)
	{
		if( (65 <= code[i])&&(code[i] <= 90) ) //large
		{
			num_each_alphabet[(int)code[i]-65]++;
			cnt++;
		}
		else if( (97 <= code[i])&&(code[i] <= 122) ) //small
		{
			num_each_alphabet[(int)code[i]-97]++;
			cnt++;
		}
	}

	return cnt;
}

void calc_freq(std::vector<float>& each_freq, int num_each_alphabet[], int num_alphabets)
{
	
	for(int i=0; i<26; ++i)
		each_freq.push_back( (float)num_each_alphabet[i]/num_alphabets *100);

}

int calc_kaiSquare(const std::vector<float>& each_freq)
{
	int min_coord =0;
	float res; 
	int shift;
	std::vector<float> kaiSquare;
	float fe[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};

	for(int i=0; i<each_freq.size(); ++i) //each_freq
	{
		res = 0;
		for(int j=0; j<26; ++j) //fe
		{
			shift = i+j;
			if(shift >= 26)
				shift -= 26;
			
			res = res + (each_freq[shift]*each_freq[shift] / fe[j]);

		}
		kaiSquare.push_back(res);
	
	}

	for (int i=0; i<kaiSquare.size(); ++i)
	{
		if(kaiSquare[i] < kaiSquare[min_coord])
			min_coord = i;
	}
	
	return min_coord;

}
	
void decrypt(std::vector<char>& code, int key)
{
	for(int i=0; i<code.size(); ++i)
	{
		if( (65 <= code[i])&&(code[i] <= 90) )
		{
			code[i] = (int)code[i] - key;
			if( 65 > (int)code[i])
				code[i] = (int)code[i] + 26;
		}
		else if( (97 <= code[i])&&(code[i] <= 122) )
		{
			code[i] = (int)code[i] - key;
			if( 97 > (int)code[i])
				code[i] = (int)code[i] + 26;
		}
	
	}
}

void print(const std::vector<char>& code)
{
	for(int i=0; i<code.size(); ++i)
	{
		std::cout << code[i];	
	}
	
	std::cout << std::endl;
}

