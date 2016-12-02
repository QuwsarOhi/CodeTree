//UVa
//441 - Lotto

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

int main()
{
	int n;
	bool first = true;
	while(scanf(" %d", &n) && n)
	{
		sp(first);
		int arr[n+1];
		fr(i, 0, n)
			scanf(" %d", &arr[i]);
		
		fr(a, 0, n-5)
			fr(b, a+1, n-4)
				fr(c, b+1, n-3)
					fr(d, c+1, n-2)
						fr(e, d+1, n-1)
							fr(f, e+1, n)
								printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
	}
	return 0;
}
