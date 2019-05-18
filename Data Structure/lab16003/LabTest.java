import java.util.*;

class LabTest {
	static Scanner in;
	public static void main(String[] args) {
		in = new Scanner(System.in);
		while(true) {
			Polynomial a = new Polynomial(128);
			Polynomial b = new Polynomial(128);

			// initialize the Polynomial a
			InitPolynomial(a, "a");
			System.out.println(a);

			// initialize the Polynomial a
			InitPolynomial(b, "b");
			System.out.println(b);
	
			Polynomial c;
			System.out.println("c = a + b");
			c = a.Add(b);
			System.out.println(c);
	
			System.out.println("d = a - b");
			Polynomial d = a.Subtract(b);
			System.out.println(d);

			System.out.println("Continue (y/n) ");
			String ans = in.next();
			if(ans.equals("n"))
				break;
		}
	}

	static void InitPolynomial(Polynomial p, String msg) {
		System.err.println("Init Polynomial " + msg);
		float coef;
		int exp;
		while (true) {
			System.err.println("Enter a term (coef, exp)");
			coef = in.nextFloat();
			exp = in.nextInt();
			if(exp == -1) {
				return;
			}
			p.NewTerm(coef, exp);
		}
	}
}

