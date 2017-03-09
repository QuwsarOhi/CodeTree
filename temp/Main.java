import java.util.*;
import java.math.BigInteger;
import java.io.*;

class Main {
	static int x;
	static BigInteger[][] dp = new BigInteger[26][160];
	static BigInteger[] p = new BigInteger[30];
	
 	static BigInteger cal(int dice_left, int current_score) {
		if(current_score >= x) {
			if(dice_left == 0)
				return BigInteger.valueOf(1);
			else
				return (BigInteger.valueOf((int)Math.pow((double)6, (double)dice_left)));
		}
		
		if(dice_left == 0 || (dice_left*6)+current_score < x)
			return BigInteger.ZERO;
		
		if(dp[dice_left][current_score].compareTo(BigInteger.valueOf(-1)) > 0) {
			System.out.println("Dp hit " + dp[dice_left][current_score] + " : " + dice_left + " " + current_score);
			return dp[dice_left][current_score];
		}
		
		BigInteger sum = BigInteger.ZERO;
		if(current_score >= x)
			sum = sum.add(BigInteger.ONE);
		for(int i = 1; i <=6; i++)
			sum = sum.add(cal(dice_left - 1, current_score + i));
		
		return dp[dice_left][current_score] = sum;
	}
	
	public static void main(String args[]) {
		for(int i = 0; i < 26; i++)
			Arrays.fill(dp[i], BigInteger.valueOf(-1));
		Scanner sc = new Scanner(System.in);
		p[0] = BigInteger.valueOf(1);
		for(int i = 1; i < 25; i++)
			p[i] = p[i-1].multiply(BigInteger.valueOf(6));
		while(true) {
			int n = sc.nextInt();
			x = sc.nextInt();
			BigInteger ans = cal(n, 0);
			if(ans.compareTo(BigInteger.ZERO) == 0)
				System.out.println("0");
			else if(ans.compareTo(p[n]) == 0)
				System.out.println("1");
			else {
				BigInteger gcd = ans.gcd(p[n]);
				System.out.println(ans.divide(gcd) + "/" + p[n].divide(gcd));
			}
		}
	}
}