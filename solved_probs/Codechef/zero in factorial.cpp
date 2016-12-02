//Codechef
//Problem url: https://www.codechef.com/problems/TLG

#include <iostream>
#include <cstdio>

using namespace std;

int zero(int n)
{
	register int sum = 0, num = 5;
	
	do{
		sum += (n/num);
		num *= 5;
	}while(n/num != 0);
	
	return sum;
}

int main()
{
	int n, x;
	
	cin >> n;
	
	while(n--)
	{
		cin >> x;
		cout << zero(x) << endl;
	}
	
	return 0;
}
