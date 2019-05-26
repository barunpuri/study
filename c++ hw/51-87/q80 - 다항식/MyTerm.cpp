#include "MyTerm.h"
#include "MyPolynomial.h"
// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e)
{
}
// copy constructor 
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp)
{
}
// overloaded operators
bool myTerm::operator == (const myTerm& term) const
{
	if( (getCoeff() == term.getCoeff())&&(getExp() == term.getExp()) )
		return true;
	else 
		return false;
}
// overloaded operators
bool myTerm::operator != (const myTerm& term) const
{
	return (getCoeff() != term.getCoeff())||(getExp() != term.getExp());
}
// overloaded operators
bool myTerm::operator < (const myTerm& term) const
{
 return exp > term.exp;
}
myTerm myTerm::operator - () const
{
 return myTerm(-coeff,exp);
}
// derivative of a term
myTerm myTerm::ddx() const
{
 if (exp == 0)
 return myTerm(0, 0);
 return myTerm(exp*coeff, exp-1);
}


// output operator
ostream& operator <<(ostream &outStream, const myTerm& term)
{
 if (term.getExp() == 0)
 if (term.getCoeff() == 0) // nothing to output
 return outStream;
 else
 return outStream << term.coeff;

 if (term.getCoeff() == 1)
 outStream << "x";
 else if (term.getCoeff() == -1)
 outStream << "-x";
 else
 outStream << term.getCoeff() << "x";
 if (term.getExp() == 1)
 return outStream;
 else
 return outStream << "^" << term.getExp();
} 

