//UVa
//url : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=976&mosmsg=Submission+received+with+ID+17972517
//Primary Arithmatic (10035)

#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0)
			break;
		int carry = 0;
		int temp1 = 0, count = 0;
		while(a != 0 || b != 0)
		{
			temp1 = a%10 + b%10 + carry;
			carry = temp1/10;
			//printf("c : %d\n", carry);
			if(carry)
				count++;
			a/=10;
			b/=10;
		}
		if(count == 0)
			printf("No carry operation.\n");
		else if(count == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", count);
	}
	return 0;
}
