//UVa
//10551 - Basic Remains
import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int base = sc.nextInt();
			if(base == 0)
				break;
			BigInteger p = new BigInteger(sc.next(), base);		//the input was in "base" base
			BigInteger m = new BigInteger(sc.next(), base);		//this was also in "base" value base
			BigInteger ans = p.mod(m);							//this answer is in decimal base
			System.out.println(ans.toString(base));				//converting decimal base to "base" base
		}
	}
}
