//UVa
//10925 - Krakovia
import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int Case = 1;
		while(true) {
			int n = sc.nextInt();
			int f = sc.nextInt();
			if(n == 0 || f == 0)
				break;
			BigInteger sum = BigInteger.ZERO;
			for(int i = 0; i < n; i++) {
				BigInteger bi = sc.nextBigInteger();
				sum = sum.add(bi);
			}
			System.out.println("Bill #" + Case++ + " costs " + sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(f)));
			System.out.println();
		}
	}
}
