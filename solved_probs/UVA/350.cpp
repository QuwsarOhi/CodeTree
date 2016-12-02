//UVa
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=286&mosmsg=Submission+received+with+ID+18102065
//350 - Pseudo-Random Numbers

#include <bits/stdc++.h>

using namespace std;

int main()
{
	for(register int c = 1; ; c++)
	{
		register long z, i, m, l;
		unordered_map<int, int>mp;
		scanf(" %ld %ld %ld %ld", &z, &i, &m, &l);
		if(z == 0 && i == 0 && m == 0 && l == 0)
			break;
		register int cycle = 1;
		int init = l;
		while(1)
		{
			l = ((z*l)+i)%m;
			//printf("psudo : %ld, %d\n", l, cycle);
			if(l == init)
				break;
			if(mp.find(l) != mp.end())
			{
				cycle--;
				break;
			}
			mp[l] = 1;
			cycle++;
		}
		printf("Case %d: %d\n", c, cycle);
	}
	return 0;
}
