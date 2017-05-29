//UVa
//389 - Basically Speaking
import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in;
		while((in = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(in);
			String num = st.nextToken();
			int p = Integer.valueOf(st.nextToken());
			int q = Integer.valueOf(st.nextToken());
			String ans = new BigInteger(num, p).toString(q);
			if(ans.length() > 7)
				System.out.printf("%7s\n", "ERROR");
			else
				System.out.printf("%7s\n", ans.toUpperCase());
		}	
	}
}
