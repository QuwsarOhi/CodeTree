//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3666&mosmsg=Submission+received+with+ID+18101742
//1225 - Digit Counting
#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int>mp;

void dig(int x)
{
	while(x != 0)
	{
		mp[x%10]++;
		x/=10;
	}
}

int main()
{
	register int t;
	scanf(" %d", &t);
	while(t--)
	{
		int n;
		scanf(" %d", &n);
		for(register int i = 1; i <= n; i++)
			dig(i);
		for(register int i = 0; i < 10; i++)
		{
			if(i == 9)
				printf("%d\n", mp[i]);
			else
				printf("%d ", mp[i]);
		}
		mp.clear();
	}
	return 0;
}
