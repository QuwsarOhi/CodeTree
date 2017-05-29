//UVa
//624 - CD
#include <bits/stdc++.h>

using namespace std;

int main()
{
	register int n, l, len, temp, cnt, m_cnt, mx, sum;
	int arr[30];
	while(scanf(" %d %d", &n, &l) != EOF)
	{
		for(register int i = 0; i < l; i++)
			scanf(" %d", &arr[i]);
		len = 1 << l;
		mx = -1;
		//printf("done %d\n", len);
		for(register int i = 0; i < len; i++)
		{
			sum = 0;
			cnt = 0;
			//printf("sum %d\n",sum);
			for(register int j = 0; j < l; j++)
			{
				if(i & (1 << j))
				{
					sum += arr[j];
					cnt++;
					//printf("*");
				}
			}
			//printf("*");
			if((sum <= n && sum > mx) || (sum <= n && sum >= mx && cnt > m_cnt))
			{
				m_cnt = cnt;
				mx = sum;
				temp = i;
			}
			
		}
		for(register int i = 0; i < l; i++)
			if(temp & (1 << i))
				printf("%d ", arr[i]);
		printf("sum:%d\n", mx);
	}
	return 0;
}
