//UVa
//10814 - Simplifying Fractions

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n-- > 0) {
			BigInteger p = sc.nextBigInteger();
			String ch = sc.next();		//Ignored
			BigInteger q = sc.nextBigInteger();
			BigInteger r = p.gcd(q);
			System.out.println(p.divide(r) + " / " + q.divide(r));
		}
	}
}
