import java.util.Scanner;

//to get input we need a function which is scanner
//this function is not in the default namespace
//so we need to import it

class input
{
	public static void main(String args[])
	{
		Scanner x = new Scanner(System.in);
		
		//here x is a variable of Scanner type
		//System.in is a function that revieves inputs from keyboard
		
		System.out.println(x.nextLine());
		
		//here the nextLine() function mainly waits for the user input
		//before giving output
	}
}
