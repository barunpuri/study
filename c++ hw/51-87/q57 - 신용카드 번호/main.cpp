#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void credit_card_num(std::ifstream& fin);
void input_data( std::ifstream& fin, std::vector<int>& cardNum);
bool check_length_of_card_num(const std::vector<int>& cardNum);
int calc_check_sum(const std::vector<int>& cardNum);

int main()
{
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for( int i=0; i<numTestCase; ++i)
		credit_card_num(fin);
	fin.close();
	
	return 0;
}

void credit_card_num(std::ifstream& fin)
{
	std::vector<int> cardNum;
	int lastNum;
	
	input_data(fin, cardNum);
	
	if( check_length_of_card_num(cardNum) )
	{
		lastNum = calc_check_sum(cardNum);
	std::cout <<lastNum;
		if( ( lastNum + cardNum[cardNum.size()-1] )%10 == 0  )
			std::cout << "1" << std::endl;
		else
			std::cout << "0" << std::endl;		
	}	
	else
		std::cout << "0" << std::endl;		


	
}

void input_data( std::ifstream& fin, std::vector<int>& cardNum)
{
	std::string num;
	fin >> num;
	for(int i=0; i<num.size(); ++i)
		cardNum.push_back(num[i]-48);
	
}

bool check_length_of_card_num(const std::vector<int>& cardNum)
{
	if( cardNum[0] == 3)
	{
		if( (cardNum.size() == 15)||(cardNum.size() == 14) )
			return true;
		else 
			return false;
	}
	else if( cardNum[0] == 4)
	{
		if( (cardNum.size() == 13)||(cardNum.size() == 16) )
			return true;
		else 
			return false;
	}
	else if( cardNum[0] == 5)
	{
		if(cardNum.size() == 16)
			return true;
		else 
			return false;
	}
	else if( cardNum[0] == 6)
	{
		if(cardNum.size() == 16)
			return true;
		else 
			return false;
	}
	else 
		return false;


}

int calc_check_sum(const std::vector<int>& cardNum)
{
	int checkSum =0;
	for(int i=0; i<cardNum.size()-1; ++i)
	{
		if( i%2 == 0)
			checkSum += cardNum[i];
		else
		{
			if( 2*cardNum[i] >= 10 )
				checkSum = checkSum + 2*cardNum[i] - 9;
			else			
				checkSum += 2*cardNum[i];
		}
	}

	return checkSum;
}












