
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
#define ll long long
#define N 1000000

int main()
{
	int coin[] = {1, 2, 3, 4}, dp[10000], n, coin_num;
	coin_num = 3;
	wh(sf("%d", &n) &&n) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int j = 0; j < coin_num; j++)
			for(int i = n; i > 0; i--)
				if(i >= coin[j] && dp[i - coin[j]])
					dp[i] = 1;
					
		pf("%d\n", dp[n]);
	}
	return 0;
}
