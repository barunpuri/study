#include <vector>
#include <algorithm>
#include "MyTerm.h"
#include "MyPolynomial.h"
/********************* add your code here *******************************/
myPolynomial::myPolynomial(int c , unsigned e )
{
	terms.push_back(myTerm(c,e));
}
myPolynomial::myPolynomial(int nTerms, int mono[])
{
	for(int i=0; i<nTerms; ++i)
		terms.push_back(myTerm(mono[2*i],mono[2*i+1]));
	std::sort(terms.begin(), terms.end());
}
// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly)
:degree(poly.getDegree())
{
	terms.clear();
	for(int i=0; i<poly.getNumTerms; ++i)
		terms.push_back(poly.getTerm(i));
}
 // overloaded operators 
bool myPolynomial::operator == (const myPolynomial &poly) const
{
	if( getNumTerms() != poly.getNumTerms() )
		return false;
	
	for( int i=0; i<getNumTerms(); ++i)
	{
		if( terms[i] != poly.terms[i] )
			return false;
	}
	return true;			
}
bool myPolynomial::operator != (const myPolynomial &poly) const
{
	return !(*this == poly);
}
myPolynomial& myPolynomial::operator += (const myPolynomial &poly)
{
	int xPos =0; 
	int yPos =0; 
	while(xPos<getNumTerms() && yPos <poly.getNumTerms() )
	{
		if( terms[xPos].getExp() == poly.terms[yPos].getExp())
		{		
			terms[xPos].setCoeff( terms[xPos].getCoeff() + poly.terms[yPos].getCoeff() ); 
			xPos++; 
			yPos++;
		}
		else if( terms[xPos].getExp() > poly.terms[yPos].getExp() )
			xPos++;
		else
		{
			terms.push_back(poly[yPos]);
			yPos++;		
		}	

	}
	for( int i=yPos; i<poly.getNumTerms(); ++i)
	{
		terms.push_back(poly[yPos]);
	}
	std::sort(terms.begin(), terms.end());

	return *this;
}
myPolynomial& myPolynomial::operator += (const myTerm& term)
{
	return *this += myPolynomial(term.getCoeff(), term.getExp() );
}
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly)
{
	int xPos =0; 
	int yPos =0; 
	while(xPos<getNumTerms() && yPos <poly.getNumTerms() )
	{
		if( terms[xPos].getExp() == poly.terms[yPos].getExp())
		{	
			if( terms[xPos].getCoeff() - poly.terms[yPos].getCoeff() != 0 )	
				terms[xPos].setCoeff( terms[xPos].getCoeff() - poly.terms[yPos].getCoeff() ); 
			else 
				terms[xPos] = myTerm;
			xPos++; 
			yPos++;
		}
		else if( terms[xPos].getExp() > poly.terms[yPos].getExp()
			xPos++;
		else
		{
			terms.push_back(-poly[yPos]);
			yPos++;		
		}	

	}
	for( int i=yPos; i<poly.getNumTerms(); ++i)
	{
		terms.push_back(-poly[yPos]);
	}
	std::sort(terms.begin(), terms.end());

	return *this;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly)
{
	


	return *this;
}
myPolynomial& myPolynomial::operator *= (int k)
{
	for(int i=0; i<getNumTerms(); ++i)
		terms[i].coeff*k;
	
	return *this;
}
myPolynomial myPolynomial::operator -() const
{
	myPolynomial poly;
	for(int i=0; i<getNumTerms(); ++i)
		poly.push_back(terms[i].getCoeff()*(-1), terms[i].getExp() );
	
	return poly;	
}
myPolynomial myPolynomial::operator *(int k) const
{
	myPolynomial poly;
	for(int i=0; i<getNumTerms(); ++i)
		poly.push_back(terms[i].getCoeff()*(k), terms[i].getExp() );
	
	return poly;
}
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const
{	
	myPolynomial res_poly;
	int xPos =0; 
	int yPos =0; 
	while(xPos<getNumTerms() && yPos <poly.getNumTerms() )
	{
		if( terms[xPos].getExp() == poly.terms[yPos].getExp())
		{		
			res_poly += myPolynomial( terms[xPos].getCoeff() + poly.terms[yPos].getCoeff(), terms[xPos].getExp() ); 
			xPos++; 
			yPos++;
		}
		else if( terms[xPos].getExp() > poly.terms[yPos].getExp()
		{
			res_poly += myPolynomial(terms[xPos]);
			xPos++;
		}
		else
		{
			res_poly += myPolynomial( poly[yPos] );
			yPos++;		
		}	

	}
	for( int i=xPos; i<getNumTers(); ++i)
		res_poly += poly[i];
	for( int i=yPos; i<poly.getNumTerms(); ++i)
		res_poly += poly[i];
	std::sort(terms.begin(), terms.end());
	
	
	return res_poly;
}
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const
{
	myPolynomial res_poly;
	int xPos =0; 
	int yPos =0; 
	while( xPos<getNumTerms() && yPos <poly.getNumTerms() )
	{
		if( terms[xPos].getExp() == poly.terms[yPos].getExp())
		{	
			if ( terms[xPos].getCoeff() - poly.terms[yPos].getCoeff() != 0 )
				res_poly += myPolynomial( terms[xPos].getCoeff() - poly.terms[yPos].getCoeff(), terms[xPos].getExp() ); 
			xPos++; 
			yPos++;
		}
		else if( terms[xPos].getExp() > poly.terms[yPos].getExp()
		{
			res_poly += myPolynomial(terms[xPos]);
			xPos++;
		}
		else
		{
			res_poly += myPolynomial( -poly[yPos] );
			yPos++;		
		}	

	}
	for( int i=xPos; i<getNumTers(); ++i)
		res_poly += poly[i];
	for( int i=yPos; i<poly.getNumTerms(); ++i)
		res_poly += -poly[i];
	std::sort(terms.begin(), terms.end());
	
	
	return res_poly;

}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const
{


	return myPolynomial();
}
long myPolynomial::operator() (int x) const // evaluate the polynomial
{
	long res=0;
	for(int i=0; i<getNumTerms(); ++i)
	{
		res += terms[i].getCoeff() * pow(x,terms[i].getExp() );
	}
	return res;
}
myTerm myPolynomial::operator[] (int n) const
{
	return terms[n];
}
int myPolynomial::getDegree() const // get a degree of the polynomial
{
	std::sort(terms.begin(), terms.end());
	return terms[0].getExp();
}
unsigned myPolynomial::getNumTerms() const // number of terms in the polynomial
{
	return terms.size();
}
myPolynomial myPolynomial::ddx() const // derivative of a polynomial
{
	myPolynomial poly;
	for(int i=0; i<getNumTerms(); ++i)
	{
		poly += myPolynomial(terms[i].getCoeff()*terms[i].getExp(),terms.[i].getExp()-1);
	}
	return poly;
}


// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
if (poly == myPolynomial::ZERO)
 return outStream << 0;
/********************* add your code here ********************************/
 return outStream;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x
