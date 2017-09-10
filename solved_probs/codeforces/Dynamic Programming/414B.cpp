// Codeforces
// B. Mashmokh and ACM
// http://codeforces.com/problemset/problem/414/B

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

int divisors[2010][2010];

int main() {
	int N, K;
	sf("%d %d", &N, &K);
	ll ans = 0;
	
	for(int i = 1; i <= N; ++i)
		divisors[1][i] = 1;
	
	
	for(int k = 2; k <= K; ++k) {
		for(int i = 1; i <= N; ++i) {
			int lim = sqrt(i);
			for(int j = 1; j <= lim; ++j) {
				if(i%j == 0) {
					divisors[k][i] += divisors[k-1][j];
					divisors[k][i] %= MOD;
					int t = i/j;
					if(t != j) {
						divisors[k][i] += divisors[k-1][t];
						divisors[k][i] %= MOD;
					}
				}
			}
			
			if(k == K) {
				ans += divisors[k][i];
				ans %= MOD;
			}
		}
	}
	
	if(K == 1)
		ans = N;
	
	pf("%lld\n", ans);
	
	return 0;
}
	


/* Another Solve

int divisors[2009][2009];

int main() {
	int N, K, ans = 0;
	sf("%d %d", &N, &K);
	
	for(int i = 1; i <= N; ++i)
		divisors[1][i] = 1;
		
	for(int k = 2; k <= K; ++k) {
		for(int i = 1; i <= N; ++i) {
			for(int x = 1; x*i <= N; ++x) {
				divisors[k][x*i] += divisors[k-1][i];
				divisors[k][x*i] %= MOD;
			}
			if(k == K) {
				ans += divisors[K][i];
				ans %= MOD;
			}
		}
	}
	
	if(K == 1)
		ans = N;
	
	pf("%d\n", ans);
	
	return 0;
}

*/
