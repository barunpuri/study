import java.util.*;

class Polynomial {
	private Term[] termArray;
	private int terms;  // number of nonzero terms
	private int capacity;   // size of termArray

	class Term {
		private float coef; //coefficient
		private int exp; //exponent
	};

	// constructor
	Polynomial(int cap) {
		capacity = cap;
		termArray = new Term[capacity];
		terms = 0;
	}

	/**
	*  Add a new term to the end of termArray
	*/
	void NewTerm(float theCoeff, int theExp) {	
		if(terms == capacity)
		{// double capacity of termArray
			capacity *=2;
			Term[] temp = new Term[capacity]; // new array
			System.arraycopy(termArray, 0, temp, 0, terms);
			termArray = temp;
		}
		termArray[terms] = new Term();
		termArray[terms].coef = theCoeff;
		termArray[terms++].exp = theExp;
	}

	Polynomial Add(Polynomial b) {
		// Return the sum of the polynomials this and b
		Polynomial c = new Polynomial(128);
		int aPos = 0, bPos = 0;
		while((aPos < terms) && (bPos < b.terms))
		if(termArray[aPos].exp == b.termArray[bPos].exp){
			float t=termArray[aPos].coef+b.termArray[bPos].coef;
			if (t != 0.0) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if(termArray[aPos].exp < b.termArray[bPos].exp){
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
		// add in remaining terms of this
		for( ; aPos < terms; aPos++)
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		for( ; bPos < b.terms; bPos++)
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
		return c;
	}		

	Polynomial Subtract(Polynomial b) {
		// Return the difference of the polynomials this and b
		Polynomial c = new Polynomial(120);
		int aPos = 0, bPos = 0;

		while((aPos < terms) && (bPos < b.terms))
		if(termArray[aPos].exp == b.termArray[bPos].exp){
			float t=termArray[aPos].coef-b.termArray[bPos].coef;
			if (t != 0.0) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if(termArray[aPos].exp < b.termArray[bPos].exp){
			c.NewTerm(-b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
		// add in remaining terms of this
		for( ; aPos < terms; aPos++)
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		for( ; bPos < b.terms; bPos++)
			c.NewTerm(-b.termArray[bPos].coef, b.termArray[bPos].exp);
		

		

		return c;
	}		

	// construct a string that shows all the terms
	public String toString() {
		String a = new String();
		a = String.format("Number of terms = %d:", terms);


		for(int i=0; i<terms; i++){
			a = a.concat("(" + termArray[i].coef + ", " + termArray[i].exp + ") ");

		}
		


		return a;
	}
}


