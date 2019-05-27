// LightOJ
// 1369 - Answering Queries

#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
typedef long long ll;

ll v[MAX];

int main() {
	int q, t, n, m, idx;
	ll val;
	scanf("%d", &t);

	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &v[i]);

		ll ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += v[i]*(n-i);
		for(int i = 1; i <= n; ++i)
			ans -= v[i]*(i-1);

		printf("Case %d:\n", Case);
		while(m--) {
			scanf("%d", &q);
			
			if(q == 0) {
				scanf("%d%lld", &idx, &val);
				++idx;
				
				ans -= v[idx]*(n-idx);
				ans += val*(n-idx);

				ans += v[idx]*(idx-1);
				ans -= val*(idx-1);

				v[idx] = val;
			}
			else {
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}