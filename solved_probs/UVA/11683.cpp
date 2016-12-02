//UVa
//11683 - Laser Sculpture

#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int h, l, past, sum;
	while(scanf(" %d", &h) &&h)
	{
		scanf(" %d", &l);
		int ind[l+1] = {};
		sum = 0;
		for(register int i = 0; i < l; i++)
			scanf(" %d", &ind[i]);
		for(register int i = 0; i < l; i++)
		{
			if(i == 0)
			{
				past = ind[i];
				sum += h - ind[i];
			}
			else
				if(past > ind[i])
					sum += past - ind[i];
			past = ind[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
