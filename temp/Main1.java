import java.util.*;
import java.math.BigInteger;
import java.io.*;

class Main1 {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("in"));
		
		while(true) {
			int a, b, c, d, e;
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			d = sc.nextInt();
			e = sc.nextInt();
			if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
				break;
			//BigInteger A = BigInteger.valueOf(a);
			//BigInteger B = BigInteger.valueOf(b);
			//BigInteger C = BigInteger.valueOf(c);
			BigInteger D = BigInteger.valueOf(d);
			BigInteger E = BigInteger.valueOf(e);
			BigInteger ans = A.multiply(B);
			ans = ans.multiply(C);
			ans = ans.multiply(D);
			ans = ans.multiply(D);
			ans = ans.multiply(E);
			System.out.println(ans.multiply(E));
		}
	}
}