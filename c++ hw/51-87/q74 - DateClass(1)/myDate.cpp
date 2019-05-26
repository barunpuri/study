#include <iostream>
#include "myDate.h"


// Constructor (생성자)
myDate::myDate(int year, int month, int day)
	: year_(year), month_(month), day_(day)
	{}

// Accessor functions (접근자)
int myDate::getDayOfMonth() const { return day_; }
int myDate::getMonth() const { return month_; }
int myDate::getYear() const { return year_; }

// Mutator functions (변경자)
void myDate::setDayOfMonth(int day)
{
	day_ = day ;
}
void myDate::setMonth(int month)
{
	month_ = month ;
}
void myDate::setYear(int year)
{
	year_ = year ;
}
void myDate::setDate(int year, int month, int day)
{
	day_ = day ;
	month_ = month ;
	year_ = year ;
}

// utility functions 
bool myDate::isLeapYear() const //윤년
{
	if( ( (year_%4==0)&&(year_%100!=0) )||(year_%400==0) )
		return true;
	else 
		return false;
}
int myDate::getDayOfWeek() const //0=Sunday, 1=Monday, ..., 6=Saturday
{
	int year = year_;
	int month = month_;
	int res;
	if( month<3 )
	{
		year -= 1;
		month += 12;
	}
	res = (year + (year / 4) - (year / 100) + (year / 400) + (13 * month + 8) / 5 + day_) % 7;
	return res%7;
}
int myDate::getDayOfYear() const //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
{
	int days[12] = {0,31,28,31,30,31,30,31,31,30,31,30};
	int res=0;	
	if( (month_ > 2)&&(isLeapYear()) )
		res += 1;
	for(int i=0; i<month_; ++i)
		res += days[month_-1];
	res += day_;

	return res;
}
int myDate::getNumHolidays() const //휴일수 계산
{
	return 0;
}
int myDate::getNumSummerTimeDays() const //써머타임 날짜수
{
	return 0;
}
void myDate::printCalendarOfMonth() const // 달력출력하기
{

}






