//UVa
//623 - 500!

import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {
	public static void main(String args[]) throws IOException{
		Vector<BigInteger> v = new Vector<BigInteger>();
		BigInteger b, fact;
		v.add(new BigInteger("1"));
		fact = new BigInteger("1");
		for(int i = 1; i <= 1000; i++) {
			b = new BigInteger(Integer.toString(i));
			fact = fact.multiply(b);
			v.add(fact);
		}
		//System.out.println(v.size());
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String x;
		while((x = br.readLine()) != null) {
			int n = Integer.valueOf(x);
			System.out.println(n + "!");
			System.out.println(v.get(n));
		}
	}
}
