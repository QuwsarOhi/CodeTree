//UVa
//10334 - Ray Through Glasses

import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//Scanner sc = new Scanner(new File("in"));
		//PrintStream o = new PrintStream(new File("out"));
		//System.setOut(o);
		//Genereting Fib numbers
		BigInteger f[] = new BigInteger[1002];
		f[0] = new BigInteger("1"); 
		f[1] = new BigInteger("2");
		for(int i = 2; i < 1002; i++)
			f[i] = (f[i-1]).add(f[i-2]);

		//Start having input
		
		while(br.ready()) {
			int x = Integer.valueOf(br.readLine());
			System.out.println(f[x]);
		}
	}
}
