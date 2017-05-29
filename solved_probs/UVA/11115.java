//UVa
//11115 - Uncle Jack


import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int r = sc.nextInt();
			int n = sc.nextInt();
			if(n == 0 && r == 0)
				break;
			BigInteger R = BigInteger.valueOf(r);
			System.out.println(R.pow(n));
		}
	}
}