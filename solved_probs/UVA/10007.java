//UVa
//10007 - Count the Trees

import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	
	public static BigInteger perm;
	
	static BigInteger C(int n, int k) {
		BigInteger c = BigInteger.ONE;
		
		perm = BigInteger.ONE;
		
		for(int i = 0; i < k; i++) {
			c = c.multiply(BigInteger.valueOf(n-i));
			BigInteger tmp = BigInteger.valueOf(i+1);
			c = c.divide(tmp);
			perm = perm.multiply(tmp);
		}
		return c;
	}
	
	static BigInteger catalan(int n) {
		BigInteger cat = C(2*n, n);
		cat = cat.divide(BigInteger.valueOf(n+1));
		return cat;
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int n = sc.nextInt();
			if(n == 0)
				break;
			System.out.println((catalan(n)).multiply(perm));
		}
	}
}