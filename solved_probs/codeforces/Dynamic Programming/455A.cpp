// Codeforces
// A.Boredom
// http://codeforces.com/problemset/problem/455/A
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

ll v[100010] = {0}, dp[100010] = {0}, mx = -1, x, n;

int main() {
	sf("%lld", &n);
	
	fr(i, 0, n) {
		sf("%lld", &x);
		v[x]++;
		mx = max(mx, x);
	}
	
	dp[1] = v[1];
	fr(i, 2, mx+1)
		dp[i] = max(v[i]*i+dp[i-2], dp[i-1]);
	pf("%lld\n", dp[mx]);
	return 0;
}
