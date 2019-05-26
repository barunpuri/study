#include <iostream>
#include <string>
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
bool myDate::isLeapYear(int year) const //윤년
{
	if( ( (year%4==0)&&(year%100!=0) )||(year%400==0) )
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
//	int days[12] = {0,31,28,31,30,31,30,31,31,30,31,30};
	int res=0;	
	if( (month_ > 2)&&(isLeapYear()) )
		res += 1;
	for(int i=0; i<month_; ++i)
		res += getLastDayOfMonth(i);
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
	int date = getDayOfWeek(3,31);
	if(date < 3) 
		return 210;
	else
		return 217;
}
void myDate::printCalendarOfMonth() const // 달력출력하기
{
	int startDay = getDayOfWeek(month_,1);
	int endDay = getLastDayOfMonth(month_);
	int week = 0;
	int date = 1-startDay;
	
	if( (endDay == 28)&&isLeapYear() )
		endDay = 29;

	std::cout<<year_<<" "<<month_<<std::endl;
	
	while(true)
	{
		if(date > 0 && date <= endDay )
			std::cout<<date<<" ";
		
		else
			std::cout<<"0 ";
		
		if(week == 6)
		{
			std::cout<<std::endl;
			week=-1;
		}
		if(week == -1 && date>= endDay)
			break;
		
		else
		{
			week++;
			date++;
		}

	}

}
int myDate::getLastDayOfMonth(int year, int month) const
{
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if( isLeapYear(year) && month == 2)
		return 29;
	else
		return days[month];
}
int myDate::getLastDayOfMonth(int month) const
{
	return getLastDayOfMonth(getYear(), month);
}
int myDate::getDays() const
{
	int sumDays = getDayOfMonth() ;
	int standY = 1582;
	for(int i=standY; i<getYear(); ++i)
	{
		if( (i%400==0)||( (i%100!=0)&&(i%4==0) ) )
			sumDays += 366;
		else 
			sumDays += 365;
	}
	int standM = 1;
	for(int i=standM; i<getMonth(); ++i)
	{
		if(i==2)
		{
			if(isLeapYear())
				sumDays += 29;
			else 
				sumDays += 28;
		}
		else if( (i==4)||(i==6)||(i==9)||(i==11) )
			sumDays += 30;
		else 
			sumDays += 31;
	}

	return sumDays;
}


int myDate::operator -(const myDate& date) const // difference between two days
{
	return getDays() - date.getDays();
}
myDate myDate::operator +(int num) const
{
	if( num < 0 )
		return *this - num*(-1);

	int day = getDayOfMonth();
	int month = getMonth();
	int year = getYear();

	while( true )
	{
		if( num + day > getLastDayOfMonth(year, month) )
		{
			num = num + day - getLastDayOfMonth(year, month);
			month += 1;
			if( month == 13 )
			{
				month = 1;
				year += 1;
			}
			day = 0;
		}			
		else
		{
		 	day = num + day;
			break;
		}				
	}

	return myDate(year,month,day);
}
myDate myDate::operator -(int num) const
{
	if( num < 0 )
		return *this + num*(-1);

	int day = getDayOfMonth();
	int month = getMonth();
	int year = getYear();

	while( true )
	{
		if( day - num < 1 )
		{
			month -= 1;
			if( month == 0 )
			{
				month = 12;
				year -= 1;
			}
			
			num = num - day ;
			day = getLastDayOfMonth(year,month);
		}			
		else
		{
		 	day = day - num;
			break;
		}			
	}

	if( year < 1582 )
		return myDate();
	return myDate(year,month,day);
}
myDate& myDate::operator ++() // prefix increment
{
	return *this += 1;
}
myDate& myDate::operator --() // prefix decrement
{
	return *this -= 1;
}
myDate myDate::operator ++(int) // postfix increment
{
	myDate c = *this;
	*this += 1;
	return c;
}
myDate myDate::operator --(int) // postfix decrement
{
	myDate c = *this;
	*this -= 1;
	return c;
}
myDate& myDate::operator =(const myDate& date)
{
	setDayOfMonth( date.getDayOfMonth() );
	setMonth( date.getMonth() );
	setYear( date.getYear() );
	return *this;
}
myDate& myDate::operator +=(int num)
{
	if( num < 0 )
		return *this -= num*(-1);

	int day = getDayOfMonth();
	int month = getMonth();
	int year = getYear();

	while( true )
	{
		if( num + day > getLastDayOfMonth(year, month) )
		{

			num = num + day - getLastDayOfMonth(year, month);
			month += 1;
			if( month == 13 )
			{
				month = 1;
				year += 1;
			}
			
			day = 0;
		}			
		else
		{
		 	day = num + day;
			break;
		}			
	}

	setDate(year,month,day);

	return *this;
}
myDate& myDate::operator -=(int num)
{
	if( num < 0 )
		return *this += num*(-1);	

	int day = getDayOfMonth();
	int month = getMonth();
	int year = getYear();

	while( true )
	{
		if( day - num < 1 )
		{
			month -= 1;
			if( month == 0 )
			{
				month = 12;
				year -= 1;
			}
			
			num = num - day ;
			day = getLastDayOfMonth(year,month);
		}			
		else
		{
		 	day = day - num;
			break;
		}			
	}

	if( year < 1582 )
		setDate(1582,1,1);
	else
		setDate(year,month,day);

	return *this;

}
bool myDate::operator >(const myDate& date) const
{
	if( getDays() > date.getDays() )
		return true;
	else
		return false;
}
bool myDate::operator >=(const myDate& date) const
{
	if( *this < date ) 
		return false;
	else
		return true;
}
bool myDate::operator <(const myDate& date) const
{
	if( getDays() < date.getDays() )
		return true;
	else
		return false;
}
bool myDate::operator <=(const myDate& date) const
{
	if( *this > date ) 
		return false;
	else
		return true;
}
bool myDate::operator ==(const myDate& date) const 
{
	if( getDays() == date.getDays() )
		return true;
	else
		return false;
}
bool myDate::operator !=(const myDate& date) const
{
	if( *this == date )
		return false;
	else
		return true;
}





