//UVa
//1237 - Expert Enough?

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

struct def
{
	char name[50];
	int l;
	int r;
}data[20000];

bool comp(const def &a, const def &b)
{
	if(a.l != b.l)
		return (a.l < b.l);
	else
		return a.r < b.r;
}


int main()
{
	register int t;
	scanf(" %d", &t);
	while(t--)
	{
		int len;
		scanf(" %d", &len);
		for(register int i = 0; i < len; i++)
			scanf(" %s %d %d", data[i].name, &data[i].l, &data[i].r);
		sort(data, data+len, comp);
		//for(register int i = 0; i < len; i++)
			//printf(" %s %d %d\n", data[i].name, data[i].l, data[i].r);
		register int q, i;
		scanf(" %d", &q);
		while(q--)
		{
			int n;
			bool found = false;
			scanf(" %d", &n);
			//printf("got %d\n", n);
			for(i = 0; i < len; i++)
			{
				if(data[i].l <= n && data[i].r >= n)
				{
					found = true;
					//printf("found %d in %s\n", n, data[i].name);
					if(i+1 < len)
					{
						//printf("sweeping\n");
						for(register int j = i+1; j < len; j++)
						{
						/*if(j == i)
						{
							printf("continuing in %s\n", data[i].name);
							continue;
						}*/
							if(data[j].l <= n && data[j].r >= n)
							{
								found = false;
								//printf("i =  %d  j = %d\n", i , j);
								//printf("false in %s\n", data[j].name);
								break;
							}
						}
					}
					break;
				}
			}
			if(found)
				printf("%s\n", data[i].name);
			if(!found)
				printf("UNDETERMINED\n");
			
		}
		if(t) printf("\n");
	}
	return 0;
}
