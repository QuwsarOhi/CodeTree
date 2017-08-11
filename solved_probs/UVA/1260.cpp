//UVa
//1260 - Sales

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

int arr[6000];

int main()
{
	register int t;
	scanf(" %d", &t);
	while(t--)
	{
		int n;
		scanf(" %d", &n);
		fr(i, 0, n)
			scanf(" %d", &arr[i]);
		register int counter = 0;
		for(register int i = 1; i < n; i++)
		{
			for(register int j = i-1; j >=0; j--)
				if(arr[j] <= arr[i])
					counter++;
		}
		printf("%d\n", counter);
				
	}
	return 0;
}
