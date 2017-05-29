//UVa
//1230 - MODEX

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int c = sc.nextInt();
		while(c-- > 0) {
			BigInteger x = sc.nextBigInteger();
			BigInteger y = sc.nextBigInteger();
			BigInteger n = sc.nextBigInteger();
			System.out.println(x.modPow(y, n));
		}
	}
}
