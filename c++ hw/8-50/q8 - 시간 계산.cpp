#include <iostream>
#include <fstream>

void hw_1_2(std::ifstream& fin);
int calc_work_sec(std::ifstream& fin);
void calc_work_time(int workdedSec);

int main()
{		
	std::ifstream	fin;
	int		numTestCase;
	
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		hw_1_2(fin);
	fin.close();
	
	return 0;

}

void hw_1_2(std::ifstream& fin)
{
	int numPeople;
	int sumWorkedSec=0;
	fin >> numPeople;
	for(int i=0; i<numPeople; ++i)
		sumWorkedSec+=calc_work_sec(fin);
	calc_work_time(sumWorkedSec);
	

}

int calc_work_sec(std::ifstream& fin)
{
	int startH, startM, startS;
	int endH, endM, endS;
	int hour, min ,sec;

	fin >> startH >> startM >> startS >> endH >> endM >> endS ;	

	hour = (endH-startH);
	min = (endM-startM);
	sec = (endS-startS);
	
	if(sec<0)
	{
		sec = 60+sec;
		min -= 1;
	}

	if(min<0)
	{
		min = 60+min;
		hour -= 1;
	}

	if(hour<0)
	{
		hour = 24+hour;
	}
	
	int workedSec;
	workedSec = hour*60*60 + min*60 + sec;

	
	return workedSec;

}

void calc_work_time(int workedSec)
{
	int d,h,m,s;
	d=workedSec/(24*60*60);
	h=workedSec%(24*60*60)/(60*60);
	m=workedSec%(24*60*60)%(60*60)/(60);
	s=workedSec%(24*60*60)%(60*60)%(60);
	
	std::cout << d <<" "<< h <<" "<< m <<" "<< s <<" " << std::endl;
}



