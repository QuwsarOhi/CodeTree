import java.util.Scanner;

class calculate
{
	public static void main(String args[])
	{
		Scanner inp = new Scanner(System.in);
		double fnum, snum, answer;
		System.out.println("Enter First Number: ");
		fnum = inp.nextDouble();
		//Here inp scanner variable is of Double type
		
		System.out.println("Enter Second Number: ");
		snum = inp.nextDouble();
		//note that the program waits for input on two stages
		//they are
		//fnum = inp.nextDouble();
		//snum = inp.nextDouble();
		
		answer = fnum + snum;
		System.out.println(answer);
	}
}
