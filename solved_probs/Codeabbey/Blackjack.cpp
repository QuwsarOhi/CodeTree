//Codeabbey
//Url: http://www.codeabbey.com/index/task_view/blackjack-counting

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int iarr[50], m, n, o;
char mem[100];

void grabber()
{
	int len = strlen(mem);
	for(register int i = 0; i < len; i++)
	{
	if(mem[i] >= '0' && mem[i] <= '9')
		iarr[m++] = mem[i] - '0';
	if(mem[i] >= 'B' && mem[i] <= 'Z')
		n++;
	if(mem[i] == 'A')
		o++;
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	register int t, sum;
	cin >> t;
	getchar_unlocked();
	while(t--)
	{
		sum = 0;
		m = n = o = 0;
		fgets(mem, 95, stdin);
		grabber();
		while(m--)
			sum += iarr[m];
		while(n--)
			sum += 10;
		while(o--)
		{
			if(sum + 11 <= 21)
				sum += 11;
			else
				sum += 1;
		}
		if(sum > 21)
			cout << "Bust ";
		else
			cout << sum << " ";
		memset(mem, 0, 99);
	}
	return 0;
}
	
