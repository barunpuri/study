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
	return getDayOfWeek(month_, day_);
}
int myDate::getDayOfWeek(int month, int day) const //0=Sunday, 1=Monday, ..., 6=Saturday
{
	int totalDay = 0;
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	totalDay += (year_ - 1) * 365;
	for (int i=1; i<year_; ++i) {
		if( (i % 400 == 0)||(i % 4 == 0 &&i % 100 != 0) )
			++totalDay;
	}
	if( isLeapYear() )
		arr[1] = 29;
	for(int i=0; i<month-1; ++i) {
		totalDay += arr[i];
	}
	totalDay += day;

	return totalDay % 7;
}
int myDate::getDayOfYear() const //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
{
	int days[12] = {0,31,28,31,30,31,30,31,31,30,31,30};
	int res=0;	
	if( (month_ > 2)&&(isLeapYear()) )
		res += 1;
	for(int i=0; i<month_; ++i)
		res += days[i];
	res += day_;

	return res;
}
int myDate::getNumHolidays() const //휴일수 계산
{
	int holyMonth[15] = {1,2,2,2,3,5,5,6,7,8,9,9,9,10,12};
	int holyDay[15] = {1,1,2,3,1,5,15,6,17,15,15,16,17,3,25};
	int res=104; // avg주말 수 
	int date = getDayOfWeek(1,1);
	if( (date == 0)||(date == 6) )
		res += 1;
	if( isLeapYear()&&( (date == 5)||(date == 6) ) )
		res += 1;

	for( int i=0; i<15; ++i)
	{
		int holy = getDayOfWeek(holyMonth[i], holyDay[i]);
		if( (holy != 0)&&(holy != 6) )
			res += 1;
	}

	return res;
}
int myDate::getNumSummerTimeDays() const //써머타임 날짜수
{
	return 0;
}
void myDate::printCalendarOfMonth() const // 달력출력하기
{

}






