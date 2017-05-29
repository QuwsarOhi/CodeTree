//UVa
//713 - Adding Reversed Numbers
import java.io.*;
import java.util.*;
import java.math.BigInteger;



class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		//Using fast IO
        //String str = br.readLine();
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String str1 = new StringBuffer(st.nextToken()).reverse().toString();
			//System.out.println(str1);
			BigInteger a = new BigInteger(str1);
			String str2 = new StringBuffer(st.nextToken()).reverse().toString();
			BigInteger b = new BigInteger(str2);
			BigInteger sum = a.add(b);
			String sum_rev = new StringBuffer(sum.toString()).reverse().toString();
			BigInteger ans = new BigInteger(sum_rev);
			System.out.println(ans);
		}
	}
}
