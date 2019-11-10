#include <bits/stdc++.h>
#define MAX 1009
#define MMAX 1231
#define MOD 1000000009
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll v[MAX], cum[MAX];
ll dp[MAX][MAX][51];
int vis[MAX][MAX][51], st = 1;

ll seg(int l, int r) {
	return (cum[r] - (l == 0 ? 0:cum[l-1]));
}

ll recur(int l, int r, int k) {
	if(k == 1)
		return seg(l, r);

	if(st == vis[l][r][k]) {
		//cout << "HIT\n";
		return dp[l][r][k];
	}

	ll ret = max(v[l], recur(l+1, r, k-1));
	for(int p = l+1; p <= r-k+1; ++p)
		ret = min(ret, max(seg(l, p),recur(p+1, r, k-1)));
	
	vis[l][r][k] = st;
	return dp[l][r][k] = ret;
}

int main() {
	int t, n, k;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &k);

		for(int i = 0; i < n; ++i)
			scanf("%lld", &v[i]);
		
		cum[0] = v[0];
		for(int i = 1; i < n; ++i)
			cum[i] = v[i] + cum[i-1];
		
		++st;
		printf("Case %d: %lld\n", Case, recur(0, n-1, k));
	}
	return 0;
}