//UVa
//11287 - Pseudoprime Numbers
import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	static class FastReader {
		public BufferedReader br;
		public StringTokenizer st;
		public String tmp_string;
		
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		String next() throws IOException {
			while(st == null || !st.hasMoreElements()) {
				tmp_string = br.readLine();
				if(tmp_string == null)
					return null;
				else
					st = new StringTokenizer(tmp_string);
			}
			return st.nextToken();
		}
		
		String nextLine() throws IOException {
			return br.readLine();
		}
	}
	
	public static void main(String args[]) throws IOException {
		FastReader fr = new FastReader();
		while(true) {
			BigInteger p = new BigInteger(fr.next());
			BigInteger a = new BigInteger(fr.next());
			if((a.compareTo(BigInteger.ZERO) == 0) && (p.compareTo(BigInteger.ZERO) == 0))
				break;
			if(!p.isProbablePrime(10) && (a.modPow(p, p).compareTo(a) == 0))
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}
}
