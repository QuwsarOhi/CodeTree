//UVa
//11821 - High-Precision Number
import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		BigDecimal sum = BigDecimal.ZERO;
		while(n > 0) {
			BigDecimal bd = new BigDecimal(br.readLine());
			if(bd.compareTo(BigDecimal.ZERO) == 0) {
				String x = sum.toString();
				for(int i = x.length()-1; i >= 0; i--) {		//Cutting off trailing zeros
					if(x.charAt(i) == '0')
						x = x.substring(0, i);
					else if(x.charAt(i) == '.') {				//if defimal point is found cut it off and we'r done!
						x = x.substring(0, i);
						break;
					}
					else
						break;
				}
				System.out.println(x);
				sum = BigDecimal.ZERO;
				n--;
				continue;
			}
			sum = sum.add(bd);	
		}
	}
}
