//UVa
//10541 - Stripe

import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	
	public static BigInteger C(int n, int k) {
		BigInteger ans = BigInteger.ONE;
		if(k > n-k)
			k = n - k;
		for(int i = 0; i < k; i++) {
			ans = ans.multiply(BigInteger.valueOf((long)(n-i)));
			ans = ans.divide(BigInteger.valueOf((long)(i+1)));
		}
		return ans;
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			int sum = 0;
			for(int i = 0; i < k; i++) {
				int x = sc.nextInt();
				sum += x;
			}
			int white = n - sum + 1;
			if((white == 0 && k == 0) || (n== k))
				System.out.println("1");
			else if((white == 0 && k > 0) || (white < k))
				System.out.println("0");
			else
				System.out.println(C(white, k));
		}
	}
}
