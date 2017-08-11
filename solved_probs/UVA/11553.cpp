//UVa
//in queue
//11553 - Grid Game
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
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()

using namespace std;

int main()
{
	int t, subset[] = {0, 1, 2, 3, 4, 5, 6, 7}, a[11][11], n, maxsum, total;
	mii mp;
	sf("%d", &t);
	wh(t--)
	{
		sf("%d", &n);
		fr(i, 0, n) fr(j, 0, n) sf("%d", &a[i][j]);
		maxsum = 10000;
		do{
			total = 0;
			fr(i, 0, n) total += a[i][subset[i]];
			maxsum = min(total, maxsum);
		}while(next_permutation(subset, subset+n));
		pf("%d\n", maxsum);
	}
	return 0;	
}
