//UVa
//343 - What Base Is This?
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = null;
		while((str = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(str);
			String str1 = st.nextToken();
			String str2 = st.nextToken();
			BigInteger b1 = null, b2 = null;
			boolean found = false;
			for(int i = 2; i <= 36; i++) {
				try {
					b1 = new BigInteger(str1, i);
				}\
				catch(Exception e) {
					continue;
				}
				for(int j = 2; j <= 36; j++) {
					try {
						b2 = new BigInteger(str2, j);
					}
					catch(Exception e) {
						continue;
					}
					if(b1.compareTo(b2) == 0) {
						System.out.println(str1 + " (base " + i + ") = " + str2 + " (base " + j + ")");
						found = true;
						break;
					}
				}
				if(found)
					break;
			}
			if(!found)
				System.out.println(str1 + " is not equal to " + str2 + " in any base 2..36");
		}
	}
}
