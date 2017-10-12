// Codeforces
// C. Gargari and Bishops
// http://codeforces.com/problemset/problem/463/C
// Math, Greedy, Chess

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

ll G[2010][2010], dd[4020], du[4020];

int main() {
	ll n, x;
	
	sf("%lld", &n);
	map<ll, ll>dd, du;
	for(ll i = 1; i <= n; ++i) {
		for(ll j = 1; j <= n; ++j) {
			sf("%lld", &x);
			G[i][j] = x;
			dd[i-j+n]+= x;
			du[i+j]+= x;
		}
	}
	
	ll Max[2] = {-1, -1};
	pll p[2];
	for(ll i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int x = (i+j)%2;
			if(Max[x] < dd[i-j+n]+du[i+j]-G[i][j]) {
				Max[x] = dd[i-j+n]+du[i+j]-G[i][j];
				p[x] = {i, j};
			}
		}
	}
	
	pf("%lld\n%lld %lld %lld %lld\n", Max[0]+Max[1], p[0].first, p[0].second, p[1].first, p[1].second);
	return 0;
}


/*
3
1 0 0
0 0 0
22 0 1

3
0 0 0
0 0 0
0 0 0
*/
