//UVa
//507 - Jill Rides Again
#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int t, start, mx, sum, m_start, m_end, n, tmp;
	scanf(" %d", &t);
	for(register int x = 1; x <= t; x++)
	{
		start = 1;
		m_end = 0;
		mx = 0;
		sum = 0;
		scanf(" %d", &n);
		for(register int i = 1; i < n; i++)
		{
			scanf(" %d", &tmp);
			sum+=tmp;
			if(sum < 0)
			{
				sum = 0;
				start = i+1;
			}
			if(sum > mx || ((sum == mx) && (i - start > m_end - m_start)))
			{
				mx = sum;
				m_start = start;
				m_end = i+1;
			}
			
		}
		if(mx)
			printf("The nicest part of route %d is between stops %d and %d\n", x, m_start, m_end);
		else
			printf("Route %d has no nice parts\n", x);
	}
	return 0;
}
