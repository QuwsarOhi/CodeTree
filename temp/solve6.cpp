// Codeforces
// C. k-Tree
// http://codeforces.com/problemset/problem/431/C
// Dynamic Programming

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
#define Equal(a, b) (abs(a-b) < EPS)
#define Greater(a, b) (a >= (b+EPS))
#define GreaterEqual(a, b) (a > (b-EPS)) 
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari) cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;

int d, k;
ll dp[110][3] = {0};

ll recur(int n, bool ok) {
	if(n == 0 && ok == 1)
		return 1;
	
	if(dp[n][ok] != -1)
		return dp[n][ok];
	
	ll ans = 0;
	for(int i = 1; i <= k; ++i) {
		if(n-i >= 0) {
			if(i >= d)
				ans += recur(n-i, 1);
			else
				ans += recur(n-i, ok);
			ans%=MOD;
		}
	}
	
	return dp[n][ok] = ans;
}

int main() {
	int n;
	fr(i, 0, 105)
		dp[i][0] = dp[i][1] = -1;
	sf("%d %d %d", &n, &k, &d);
	pf("%lld\n", recur(n, 0));
	
	return 0;
}
