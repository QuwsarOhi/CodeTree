class test
{
	private static int a;
	
	private static int func(int x)
	{
		int z = 0;
		z += 5;
		System.out.println("Running " + x);
		System.out.println(a);
		return x;
	}
	
	private static void fun()
	{
		System.out.println(a);
		a = a+4;
		System.out.println(a);
	}
	
	public static void main(String argv[])
	{
		System.out.println("OK");
		int p = test.func(5);
		System.out.println(p);
		a = 2;
		func(6);
		System.out.println(a);
	}
}
