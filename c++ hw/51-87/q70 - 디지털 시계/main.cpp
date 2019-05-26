#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

void input_data(std::ifstream& fin, int& hour, int& min, std::string& meridiem, int& change);
void digital_clock(std::ifstream& fin);
void time_passed(int& hour, int& min, std::string& meridiem, int change);

int main()
{
	std::ifstream 	fin;
	int 		numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		digital_clock(fin);
	fin.close();
	
	return 0;
}

void digital_clock(std::ifstream& fin)
{
	int hour, min;
	std::string meridiem = "";
	int change;
	std::string nums[60] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59" };
	
	input_data(fin, hour, min, meridiem, change);

	time_passed(hour, min, meridiem, change);

	std::cout << nums[hour] << ":" << nums[min] << meridiem << std::endl;

}

void input_data(std::ifstream& fin, int& hour, int& min, std::string& meridiem, int& change)
{
	std::string data; 
	fin >> data >> change; 
	hour = (data[0]-48)*10 + data[1]-48 ;
	min = (data[3]-48)*10 + data[4]-48 ;
	
	meridiem.insert(0,1,data[5]);
	meridiem.insert(1,1,data[6]);

}

void time_passed(int& hour, int& min, std::string& meridiem, int change)
{
	if( change >= 1400 ) 
		change = change % 1400;
	else if( change < -1400 ) 
		change = (change*(-1) %1400) *(-1);

	change = change + min ;
	min = change % 60;
	change = change - min;
	change = change /60;
	
	change = change + hour;
	hour = change %12;
	change = change - hour;
	
	if( hour == 0 )
		hour = 12;

	change = change / 12;
	if( change % 2 != 0 )
	{
		if( meridiem == "AM")
			meridiem = "PM";
		else
			meridiem = "AM";
	}
	

}
