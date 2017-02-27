//UVa
//10235 - Simply Emirp

import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;


class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		//NOTE : this reverse can also be done by math as the range of input doesnt require biginteger implementation
		//this method is used to get familiarized with these usages
		/*try {
			//Scanner sc = new Scanner(new File("in"));
			//PrintStream o = new PrintStream(new File("out"));
			//System.setOut(o);*/
		
		while(sc.hasNext()) {															//Equivalent to EOF or hasNextInt()
			int n = sc.nextInt();
			BigInteger bn = BigInteger.valueOf(n);										//integer to BigInt
			String rev_str = new StringBuffer(bn.toString()).reverse().toString();		//first making bn a StringBuffer, then reversing it and again making string
			int rev_n = Integer.parseInt(rev_str);										//string to int
			BigInteger rev_bn = BigInteger.valueOf(rev_n);								//convertnig int to bigint
			System.out.print(n + " is ");
			if(!bn.isProbablePrime(10))													//Miller Rabins algorithm, use 10 as parameter by default
				System.out.println("not prime.");										//it returns possibility as 1 - (1/2)^parameter_given_by_user
			else if(n != rev_n && rev_bn.isProbablePrime(10))
				System.out.println("emirp.");
			else
				System.out.println("prime.");
				
		}
		/*}
		//catch(FileNotFoundException ex) {
			//System.out.println("file not found");
		}*/
	}
}
