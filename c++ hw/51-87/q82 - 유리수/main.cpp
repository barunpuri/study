#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;



using namespace std;
class myRational
{
public:
 myRational(long num=0, long den=1); 
 myRational(const myRational &rat); 
 long getNumerator() const; 
 long getDenominator() const; 
 void setNum(long num);
 void setDen(long den);
 void reduce();
 myRational reciprocal() const; 
 myRational operator ++();
 myRational operator ++(int);
 myRational operator --();
 myRational operator --(int);
 myRational operator -();
 myRational& operator =(int num);
 myRational& operator =(const myRational&r);
 myRational& operator +=(int num);
 myRational& operator +=(const myRational& r);
 myRational& operator -=(int num);
 myRational& operator -=(const myRational& r);
 myRational& operator *=(int num);
 myRational& operator *=(const myRational& r);
 myRational& operator /=(int num);
 myRational& operator /=(const myRational& r);
private:
 // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
 long _num;
 long _den; // denominator
 long gcd(long m, long n); // 최대공약수
 
};

ostream &operator <<(ostream &outStream, const myRational& r);
istream &operator >>(istream &inStream, myRational& r);
myRational operator +(int num, const myRational& r) ; //const;
myRational operator +(const myRational& r, int num) ; //const;
myRational operator +(const myRational& r1, const myRational& r2) ; //const;
myRational operator -(int num, const myRational& r) ; //const;
myRational operator -(const myRational& r, int num) ; //const;
myRational operator -(const myRational& r1, const myRational& r2) ; //const;
myRational operator *(int num, const myRational& r) ; //const;
myRational operator *(const myRational& r, int num) ; //const;
myRational operator *(const myRational& r1, const myRational& r2) ; //const;
myRational operator /(int num, const myRational& r) ; //const;
myRational operator /(const myRational& r, int num) ; //const;
myRational operator /(const myRational& r1, const myRational& r2) ; //const;
bool operator <(int num, const myRational& r) ; //const;
bool operator <(const myRational& r, int num) ; //const;
bool operator <(const myRational& r1, const myRational& r2) ; //const;
bool operator <=(int num, const myRational& r) ; //const;
bool operator <=(const myRational& r, int num) ; //const;
bool operator <=(const myRational& r1, const myRational& r2) ; //const;
bool operator >(int num, const myRational& r) ; //const;
bool operator >(const myRational& r, int num) ; //const;
bool operator >(const myRational& r1, const myRational& r2) ; //const;
bool operator >=(int num, const myRational& r) ;//const;
bool operator >=(const myRational& r, int num) ; //const;
bool operator >=(const myRational& r1, const myRational& r2) ; //const;
bool operator ==(int num, const myRational& r) ; //const;
bool operator ==(const myRational& r, int num) ; //const;
bool operator ==(const myRational& r1, const myRational& r2) ; //const;
bool operator !=(int num, const myRational& r) ; //const;
bool operator !=(const myRational& r, int num) ; //const;
bool operator !=(const myRational& r1, const myRational& r2) ; //const;








void testSimpleCase();
void testDataFromFile();
void sort(ifstream& fin);
int main()
{
 testSimpleCase();
 testDataFromFile();
}
void testSimpleCase()
{
 myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
 cout << frac1 << " " << frac2 << " " << frac3 << " "
 << frac4 << " " << frac5 << endl;
 cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
 // Check arithmetic operators
 cout << frac1 * frac2 << " "
 << frac1 + frac3 << " "
 << frac2 - frac1 << " "
 << frac3 / frac2 << endl;
 // Check comparison operators 
 cout << ((frac1 < frac2) ? 1 : 0) << " "
 << ((frac1 <= frac2) ? 1 : 0) << " "
 << ((frac1 > frac2) ? 1 : 0) << " "
 << ((frac1 >= frac2) ? 1 : 0) << " "
 << ((frac1 == frac2) ? 1 : 0) << " "
 << ((frac1 != frac2) ? 1 : 0) << " "
 << ((frac2 < frac3) ? 1 : 0) << " "
 << ((frac2 <= frac3) ? 1 : 0) << " "
 << ((frac2 > frac3) ? 1 : 0) << " "
 << ((frac2 >= frac3) ? 1 : 0) << " "
 << ((frac2 == frac3) ? 1 : 0) << " "
 << ((frac2 != frac3) ? 1 : 0) << endl;
 cout << (frac6 = frac3) << " ";
 cout << (frac6 += frac3) << " ";
 cout << (frac6 -= frac3) << " ";
 cout << (frac6 *= frac3) << " ";
 cout << (frac6 /= frac3) << endl;
 cout << -frac6 << endl;
 frac6 = (++frac4) + 2;
 frac7 = 2 + (frac4++);
 cout << frac4 << " " << frac6 << " " << frac7 << endl;
 frac6 = (--frac4) - 2;
 frac7 = 2 - (frac4--);
 cout << frac4 << " " << frac6 << " " << frac7 << endl;
 cout << 2 * frac3 << " " << frac3 * 2 << " "
 << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
	ifstream fin;
	int numTestCase;
	fin.open("input.txt");
	fin >> numTestCase;
	for(int i=0; i<numTestCase; ++i)
		sort(fin);
	fin.close();
} 

void sort(ifstream& fin)
{
	int numRational, num, den;
	vector<myRational> data;
	fin >> numRational;
	for(int i=0; i<numRational; ++i)
	{
		fin >> num >> den;
		data.push_back(myRational(num,den));
	}

	sort(data.begin(), data.end());

	for(int i=0; i<numRational; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}







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
