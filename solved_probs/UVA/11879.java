//UVa
//11879 - Multiple of 17
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		//fast IO
		BigInteger zro = BigInteger.ZERO;
		BigInteger d = new BigInteger("17");
		while(true) {
			BigInteger n = new BigInteger(br.readLine());
			if(n.compareTo(zro) == 0)
				break;
			BigInteger remain = n.mod(d);
			if(remain.compareTo(zro) == 0)
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
