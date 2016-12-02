//UVa
//11565 - Simple Equations

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main()
{
	register int t;
	scanf("%d", &t);
	while(t--)
	{
		bool found = false;
		int a, b, c;
		scanf(" %d %d %d", &a, &b, &c);
		for(register int x = -22; x <= 22 && !found; x++)
		{
			if(x*x <= c)
				for(register int y = -100; y <= 100 && !found; y++)
				{
					if((y != x) && (x*x + y*y <= c))
						for(register int z = -100; z <= 100 && !found; z++)
						{
							if(x != z && y != z && x+y+z == a && x*x+y*y+z*z == c && x*y*z == b && !found)
							{
								printf("%d %d %d\n", x, y, z);
								found = true;;
							}
						}
				}
		}
		if(!found)
			printf("No solution.\n");
	}
	return 0;
}
