//UVA
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2307
//Summing Digits

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register long n, sum;
	while(1)
	{
		sum = 0;
		cin >> n;
		if(n == 0)
			break;
		while((n%10) != n)
		{
			sum += (n%10);
			n /= 10;
			if((n%10) == n)
			{
				sum += (n%10);
				n = sum;
				sum = 0;
			}	
		}
		if(n != 0)
			sum += n;
		cout << sum << endl;
	}
	return 0;
}
