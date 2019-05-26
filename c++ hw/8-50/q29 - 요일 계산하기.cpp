#include <iostream>
#include <fstream>

void q29(std::ifstream& fin);
bool isLeapYear(int year);
int yearsToDays(int year);
int monthsToDays(int month, bool isLeapYear) ;
int detDate(int days);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		q29(fin);
	fin.close();
	
	return 0;

}

void q29(std::ifstream& fin)
{
	int sumDays = 0;

	int year, month, day;
	fin >> year >> month >> day;
	
	sumDays += yearsToDays(year);
	sumDays += monthsToDays(month, isLeapYear(year));
	sumDays += day;

	std::cout << detDate(sumDays) << std::endl;

}

bool isLeapYear(int year)
{
	if( (year%400==0)||( (year%100!=0)&&(year%4==0) ) )
		return true;
	else 
		return false;
}

int yearsToDays(int year)   
{
	int standY = 1582;
	int days=0;
	
	for(int i=standY; i<year; ++i)
	{
		if( (i%400==0)||( (i%100!=0)&&(i%4==0) ) )
			days += 366;
		else 
			days += 365;
	}
	return days;
}

int monthsToDays(int month, bool isLeapYear) 
{
	int standM = 1;
	int days=0;
	
	for(int i=standM; i<month; ++i)
	{
		if(i==2)
		{
			if(isLeapYear)
				days += 29;
			else 
				days += 28;
		}
		else if( (i==4)||(i==6)||(i==9)||(i==11) )
			days += 30;
		else 
			days += 31;
	}
	return days;
}

int detDate(int days)
{
	if( days%7 == 3)
		return 0;
	else if( days%7 == 4)
		return 1;
	else if( days%7 == 5)
		return 2;
	else if( days%7 == 6)
		return 3;
	else if( days%7 == 0)
		return 4;
	else if( days%7 == 1)
		return 5;
	else 
		return 6;
}



