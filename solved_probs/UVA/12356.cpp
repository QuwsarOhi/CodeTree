//UVa
//12356 - Army Buddies
//TLE code below

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, d;
	while(scanf(" %d %d", &s, &d) && s && d)
	{
		int lside[s+1];
		int rside[s+1];
		for(register int i = 0; i <= s; i++)
		{
			lside[i] = i - 1;
			rside[i] = i + 1;
		}
		while(d--)
		{
			int l, r;
			scanf(" %d %d", &l, &r);
			if(l > r)swap(l, r);
			if(lside[l] > 0)
				printf("%d ", lside[l]);
			else
				printf("* ");
			if(rside[r] > s)
				printf("*\n");
			else
				printf("%d\n", rside[r]);
				
			lside[rside[r]] = lside[l];
			rside[lside[l]] = rside[r];
		}
		printf("-\n");
	}
	return 0;
}

/*
//GOT TLE--------------------------------------
// 12356 - Army Buddies 

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, d;
	while(scanf(" %d %d", &s, &d) && s && d)
	{
		int arr[s+2] = {}, l, r;
		while(d--)
		{
			bool g_r = false, g_l = false;
			scanf(" %d %d", &l, &r);
			if(l == r)
				arr[l] = -1;
			else
			{
				arr[l] = r;
				arr[r] = l;
			}
			if(l > r)swap(l, r);
			if(l-1 > 0)
			{
				if(arr[l-1] != 0)
					for(register int i = l-1; i != 0; )
					{
						if(arr[i] > 0 && arr[i] < i)
						{
							i = arr[i]; //jumping to that position;
							continue;
						}
						else if(arr[i] == 0)
						{
							l = i;
							break;
						}
						i--;
				}	
				else
				{
					printf("%d ", l-1);
					g_l = true;
				}
				if(!g_l && arr[l] == 0 && l)
					printf("%d ", l);
				else if(!g_l)
					printf("* ");
			}
			else
				printf("* ");
			if(r+1 < s+1)
			{
				if(arr[r+1] != 0)
					for(register int i = r; i != s+1; )//problem, i++ causes problem here
					{
						if(arr[i] > 0 && arr[i] > i)
						{
							i = arr[i];
							continue;
						}
						else if(arr[i] == 0)
						{
							r = i;
							break;
						}
						i++;
					}
				else
				{
					printf("%d\n", r+1);
					g_r = true;
				}
				if(!g_r && arr[r] == 0 && r <= s)
					printf("%d\n", r);
				else if(!g_r)
					printf("*\n");
			}
			else
				printf("*\n");
		}
		printf("-\n");
	}
	return 0;
}
*/
