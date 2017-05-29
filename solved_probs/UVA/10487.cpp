//UVa
//10487 - Closest Sums

#include <bits/stdc++.h>
#define pb push_back
#define sp(b) if(!b)printf("\n"); b = false;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b);
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
int arr[1500];

int main()
{
	register int c, q, cse = 1;
	while(scanf(" %d", &c) && c)
	{
		register int len = 0, store = 0;
		fr(i, 0, c)
		{
			scanf(" %d", &arr[len++]);
			store += arr[len-1];
		}
		scanf(" %d", &q);
		printf("Case %d:\n", cse);
		//fr(i, 0, len)
			//printf("%d ", arr[i]);
		//printf("\n");
		fr(i, 0, q)
		{
			//printf("len %d\n", len);
			int sum, a, b, mn = store;
			scanf(" %d", &sum);
			fr(i, 0, len-1)
				fr(j, i+1, len)
				{
					if(abs(arr[i] + arr[j] - sum) <= mn)
					{
						a = arr[i];
						b = arr[j];
						mn = abs(abs(arr[i] + arr[j]) - sum);
						//printf("a = %d b = %d sum = %d mn = %d\n", a, b, sum, mn);
					}
				}
			printf("Closest sum to %d is %d.\n", sum, a+b);
		}
		cse++;	
	}
	return 0;
}
