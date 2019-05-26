#ifndef _MYDATE_H_
#define _MYDATE_H_
#include <iostream>

using namespace std;

class myDate {

	// friend 함수
	friend ostream &operator <<(ostream &outStream, const myDate& date)
{
	std::string nums[32] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};	
	outStream << nums[date.getDayOfMonth()] << "/" << nums[date.getMonth()] << "/" << date.getYear();
	
	return outStream;
}
friend istream &operator >>(istream &inStream, myDate& date)
{
	int year, month, day;
	inStream >> year >> month >> day ;
	date.setDayOfMonth(day);
	date.setMonth(month);
	date.setYear(year);
}
friend myDate operator +(int num, const myDate& date)
{
	if( num < 0 ) 
		return date - num*(-1);
	else
		return date + num;
}

public:
 	// Constructor (생성자)
 	myDate(int year=1582, int month=1, int day=1);
 	// Accessor functions (접근자)
 	int getDayOfMonth() const;
 	int getMonth() const;
 	int getYear() const;
 	// Mutator functions (변경자)
 	void setDayOfMonth(int day);
 	void setMonth(int month);
 	void setYear(int year);
 	void setDate(int year, int month, int day);
 	// utility functions 
 	bool isLeapYear() const; //윤년
 	bool isLeapYear(int year) const ;
 	int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
	int getDayOfWeek(int month, int day) const;
 	int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
 	int getNumHolidays() const; //휴일수 계산
 	int getNumSummerTimeDays()const; //써머타임 날짜수
 	void printCalendarOfMonth() const; // 달력출력하기
	int getLastDayOfMonth(int year, int month) const;
	int getLastDayOfMonth(int month) const;
	int getDays() const;

	// Operators overloaded
 	int operator -(const myDate& date) const; // difference between two days
 	myDate operator +(int num) const;
 	myDate operator -(int num) const;
 	myDate& operator ++(); // prefix increment
 	myDate& operator --(); // prefix decrement
 	myDate operator ++(int); // postfix increment
 	myDate operator --(int); // postfix decrement
 	myDate& operator =(const myDate& date);
 	myDate& operator +=(int num);
 	myDate& operator -=(int num);
 	bool operator >(const myDate& date) const;
 	bool operator >=(const myDate& date) const;
 	bool operator <(const myDate& date) const;
 	bool operator <=(const myDate& date) const;
 	bool operator ==(const myDate& date) const; 
 	bool operator !=(const myDate& date) const;

private:
 	// information hiding : implement as you wish
	int year_;
	int month_;
	int day_;
		
};
#endif //_MYDATE_H_
