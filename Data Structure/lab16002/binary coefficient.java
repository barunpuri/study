import java.util.*;

/**
 * Lab 002 
 * @version 1.0
 * @author Sanghwan Lee
 * @id 20150001
 */

class Lab {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(true) {
			System.err.println("Enter n m : ");
			int n = in.nextInt();
			int m = in.nextInt();
			if(n == 0) 
				break;

			System.out.print("Combination(" + n + ", " + m + ") : ");
			System.out.println(Combi(n, m));

		}
	}
	static int Combi(int n, int m) {

	// need to implement

	if( n==m || m==0)
		return 1;
	
	return Combi(n-1,m) + Combi(n-1, m-1);

	}
}
