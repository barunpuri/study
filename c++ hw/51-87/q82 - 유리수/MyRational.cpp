#include "MyRational.h"
#include <iostream>
using namespace std;
myRational::myRational(long num, long den)
	:_num(num), _den(den)
{
	if( _den < 0 )
	{
		_num *= -1;
		_den *= -1;
	}
	reduce();
}
myRational::myRational(const myRational &rat)
{
	_num = rat.getNumerator();
	_den = rat.getDenominator();
}
long myRational::getNumerator() const
{
	return _num;
}
long myRational::getDenominator() const
{
	return _den;
}
void myRational::setNum(long num)
{
	_num = num;
}
void myRational::setDen(long den)
{
	_den = den;
}
myRational myRational::reciprocal() const
{
	return myRational( getDenominator(), getNumerator() );
}
myRational myRational::operator ++()
{
	return *this += 1;
}
myRational myRational::operator ++(int)
{
	myRational c = *this;
	*this += 1;
	return c;
}
myRational myRational::operator --()
{
	return *this -= 1;
}
myRational myRational::operator --(int)
{
	myRational c = *this;
	*this -= 1;
	return c;
}
myRational myRational::operator -()
{
	_num *= -1;
	return *this;
}
myRational& myRational::operator =(int num)
{
	return *this = myRational(num);
}
myRational& myRational::operator =(const myRational&r)
{
	_num = r.getNumerator();
	_den = r.getDenominator();
	return *this;
}
myRational& myRational::operator +=(int num)
{
	return *this += myRational(num);
}
myRational& myRational::operator +=(const myRational& r)
{
	_num = _num*r.getDenominator() + _den * r.getNumerator();
	_den *= r.getDenominator();
	reduce();
	return *this;
}
myRational& myRational::operator -=(int num)
{
	return *this -= myRational(num);
}
myRational& myRational::operator -=(const myRational& r)
{
	_num = _num*r.getDenominator() - _den*r.getNumerator();
	_den *= r.getDenominator();
	reduce();
	return *this;
}
myRational& myRational::operator *=(int num)
{
	return *this *= myRational(num);
}
myRational& myRational::operator *=(const myRational& r)
{
	_num *= r.getNumerator();
	_den *= r.getDenominator();
	reduce();
	return *this;
}
myRational& myRational::operator /=(int num)
{
	return *this /= myRational(num);
}
myRational& myRational::operator /=(const myRational& r)
{
	if( r.getNumerator() == 0 )
	{
		_num = 0;
		_den = 1;
	}
	else
	{
		_num *= r.getDenominator();
		_den *= r.getNumerator();
		reduce();
	}
	return *this;
}
ostream &operator <<(ostream &outStream, const myRational& r)
{
 if (r.getNumerator() == 0)
 outStream << 0;
 else if (r.getDenominator() == 1)
 outStream << r.getNumerator();
 else
 outStream << r.getNumerator() << "/" << r.getDenominator();
 return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
 long num , den;
 inStream >> num >> den;
 if (den == 0)
 {
 r.setNum(0); 
 r.setDen(1);
 }
 else
 {
 r.setNum(num);
 r.setDen(den);
 }
 r.reduce();
 return inStream;
}
long myRational::gcd(long m, long n)
{
 if (m == n)
 return n;
 else if (m < n)
 return gcd(m, n-m);
 else
 return gcd(m-n, n);
}
void myRational::reduce()
{
 if (_num == 0 || _den == 0)
 {
 _num = 0;
 _den = 1;
 return;
 }
 if (_den < 0)
 {
 _den *= -1;
 _num *= -1;
 }
 if (_num == 1)
 return;
 int sgn = (_num < 0 ? -1 : 1);
 long g = gcd(sgn * _num, _den);
 _num /= g;
 _den /= g;
} 
myRational operator +(int num, const myRational& r) //const
{
	return myRational(num) + r;
}
myRational operator +(const myRational& r, int num) //const
{
	return myRational(num) + r;
}
myRational operator +(const myRational& r1, const myRational& r2) //const
{
	myRational r;
	r.setNum( r1.getNumerator()*r2.getDenominator() + r2.getNumerator()*r1.getDenominator() );
	r.setDen( r1.getDenominator()*r2.getDenominator() );
	r.reduce();
	return r;
	
}
myRational operator -(int num, const myRational& r) //const
{
	return myRational(num) - r;
}
myRational operator -(const myRational& r, int num) //const
{
	return r - myRational(num);
}
myRational operator -(const myRational& r1, const myRational& r2) //const
{
	myRational r;
	r.setNum( r1.getNumerator()*r2.getDenominator() - r2.getNumerator()*r1.getDenominator() );
	r.setDen( r1.getDenominator()*r2.getDenominator() );
	r.reduce();
	return r;
}
myRational operator *(int num, const myRational& r) //const
{
	return myRational(num) * r;
}
myRational operator *(const myRational& r, int num) //const
{
	return myRational(num) * r;
}
myRational operator *(const myRational& r1, const myRational& r2) //const
{
	myRational r;
	r.setNum( r1.getNumerator()*r2.getNumerator() );
	r.setDen( r1.getDenominator()*r2.getDenominator() );
	r.reduce();
	return r;
}
myRational operator /(int num, const myRational& r) //const
{
	return myRational(num) / r;
}
myRational operator /(const myRational& r, int num) //const
{
	return r / myRational(num);
}
myRational operator /(const myRational& r1, const myRational& r2) //const
{
	if( r2.getNumerator() == 0)
		return myRational();
	else
		return r1 * r2.reciprocal();
}
bool operator <(int num, const myRational& r) //const
{
	return myRational(num) < r;
}
bool operator <(const myRational& r, int num) //const
{
	return r < myRational(num);
}
bool operator <(const myRational& r1, const myRational& r2) //const
{
	int num1, num2;
	num1 = r1.getNumerator() * r2.getDenominator();
	num2 = r2.getNumerator() * r1.getDenominator();
	if( num1 < num2 )
		return true;
	else
		return false;
}
bool operator <=(int num, const myRational& r) //const
{
	return myRational(num) <= r;
}
bool operator <=(const myRational& r, int num) //const
{
	return r <= myRational(num);
}
bool operator <=(const myRational& r1, const myRational& r2) //const
{
	int num1, num2;
	num1 = r1.getNumerator() * r2.getDenominator();
	num2 = r2.getNumerator() * r1.getDenominator();
	if( num1 <= num2 )
		return true;
	else
		return false;
}
bool operator >(int num, const myRational& r)// const
{
	return myRational(num) > r; 
}
bool operator >(const myRational& r, int num) //const
{
	return r > myRational(num);
}
bool operator >(const myRational& r1, const myRational& r2) //const
{
	return !( r1 <= r2 );
}
bool operator >=(int num, const myRational& r) //const 
{
	return myRational(num) >= r;
}
bool operator >=(const myRational& r, int num) //const
{
	return r >= myRational(num);
}
bool operator >=(const myRational& r1, const myRational& r2) //const
{
	return !( r1 < r2 );
} 
bool operator ==(int num, const myRational& r) //const 
{
	return myRational(num) == r;
}
bool operator ==(const myRational& r, int num) //const
{
	return r == myRational(num);
}
bool operator ==(const myRational& r1, const myRational& r2) //const 
{
	if( (r1.getNumerator() == r2.getNumerator())&&(r1.getDenominator() == r2.getDenominator()) )
		return true;
	else
		return false;
}
bool operator !=(int num, const myRational& r) //const 
{
	return myRational(num) != r;
}
bool operator !=(const myRational& r, int num) //const
{ 
	return r != myRational(num);
}
bool operator !=(const myRational& r1, const myRational& r2) //const 
{
	return !( r1 == r2 );
}
