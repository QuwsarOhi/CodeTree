import java.util.*;
import java.Math.BigInteger;

class Main{
	public static void main(String args[]) {
		int x;
		string x;
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		BigInteger lim = new BigInteger.valueOf("2147483647");
		while(x-- >= 0) {
			BigInteger q = sc.nextBigInteger();
			BigInteger sum = BigInteger.Zero;
			while(q.compareTo(lim) == 1)
				sum = sum.add(q);
			