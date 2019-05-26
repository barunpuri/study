#include <cmath>
#include "myComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
 realPart = real;
 imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number)
{
 realPart = number.realPart;
 imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const
{
 return realPart;
}
int myComplex::getImaginaryPart() const
{
 return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real)
{
 realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
 imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
 realPart = real;
 imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
 int newReal = realPart + number.realPart;
 int newImag = imaginaryPart + number.imaginaryPart;
 return myComplex (newReal, newImag);
} 
myComplex myComplex::operator +(int value) const
{
 return myComplex(value) + (*this);
}
myComplex myComplex::operator -(const myComplex& number) const
{
 int newReal = realPart - number.realPart;
 int newImag = imaginaryPart - number.imaginaryPart;
 return myComplex (newReal, newImag);
} 
myComplex myComplex::operator -(int value) const
{
 return (*this) - myComplex(value);
}
myComplex myComplex::operator *(const myComplex& number) const
{
 int newReal = realPart*number.getRealPart() - getImaginaryPart()*number.getImaginaryPart();
 int newImag = realPart*number.getImaginaryPart() + getImaginaryPart()*number.getRealPart();
 return myComplex(newReal, newImag);
} 
myComplex myComplex::operator *(int value) const
{
 return myComplex(value*getRealPart(), value*getImaginaryPart());
}
// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
 this->realPart = number.realPart;
 this->imaginaryPart = number.imaginaryPart;
 return *this;
}
myComplex& myComplex::operator =(int value)
{
 realPart = value;
 imaginaryPart = 0;
 return *this;
}
myComplex& myComplex::operator +=(const myComplex& number) 
{
 int realPart = getRealPart();
 int imaginaryPart = getImaginaryPart();
 setRealPart(realPart + number.realPart);
 setImaginaryPart(imaginaryPart + number.imaginaryPart);
 return *this;
} 
myComplex& myComplex::operator +=(int value) 
{
 return (*this) += myComplex(value);
}
myComplex& myComplex::operator -=(const myComplex& number) 
{
 int realPart = getRealPart();
 int imaginaryPart = getImaginaryPart();
 setRealPart(realPart - number.realPart);
 setImaginaryPart(imaginaryPart - number.imaginaryPart);
 return *this;
} 
myComplex& myComplex::operator -=(int value) 
{
 return (*this) -= myComplex(value);
}
myComplex& myComplex::operator *=(const myComplex& number) 
{
 int realPart = getRealPart();
 int imaginaryPart = getImaginaryPart();
 setRealPart(realPart*number.getRealPart() - getImaginaryPart()*number.getImaginaryPart());
 setImaginaryPart(realPart*number.getImaginaryPart() + getImaginaryPart()*number.getRealPart());
 return *this;
} 
myComplex& myComplex::operator *=(int value) 
{
 return *this *= myComplex(value);
}
// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
 return (realPart == number.realPart) &&
 (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
 return (realPart != number.realPart) ||
 (imaginaryPart != number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const
{
 return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
 return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
 return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
 return norm() <= number.norm();
}
// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
 return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~() // unary minus
{
 return myComplex(realPart, -imaginaryPart);
}
myComplex myComplex::operator ++() // unary minus
{
 return *this += 1;
}
myComplex myComplex::operator ++(int) // unary minus
{
 myComplex c = *this;
 *this += 1;
 return c;
}
myComplex myComplex::operator --() // unary minus
{
 return *this -= 1;
}
myComplex myComplex::operator --(int) // unary minus
{
 myComplex c = *this;
 *this -= 1;
 return c;
}

// private function
int myComplex::norm() const
{
 return realPart * realPart + imaginaryPart * imaginaryPart;
}

