//UVa
//763 - Fibinary Numbers

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
		BigInteger f[] = new BigInteger[102];
		f[0] = new BigInteger("1"); 
		f[1] = new BigInteger("2");
		for(int i = 2; i < 102; i++)
			f[i] = (f[i-1]).add(f[i-2]);

		//Start having Input
		
		boolean first = true;

		while(br.ready()) {
			String a = br.readLine();
			String b = br.readLine();
			
			if(!first)
				System.out.println();
			first = false;
			
			if(br.ready())
				br.readLine();		//eating up extra space
				
			BigInteger x = BigInteger.ZERO;
			
			for(int i = a.length(); i > 0; i--)
				if(a.charAt(i-1) == '1')
					x = x.add(f[a.length() - i]);
			for(int i = b.length(); i > 0; i--)
				if(b.charAt(i-1) == '1')
					x = x.add(f[b.length() - i]);
			int pos = Arrays.binarySearch(f, x);
			String ans = "";
			if(pos < 0)
				pos = (pos*-1) - 2;
			for(int i = pos; i >= 0; i--) {
				if(x.compareTo(f[i]) >= 0) {
					ans += "1";
					x = x.subtract(f[i]);
				}
				else
					ans += "0";
			}
			if(ans.length() == 0)
				System.out.println("0");
			else
				System.out.println(ans);
		}
	}
}
