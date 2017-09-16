// Codeforces
// A. Two Bags of Potatoes
// http://codeforces.com/problemset/problem/239/A

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

int main() {
	ll y, k, n, st;
	sf("%lld %lld %lld", &y, &k, &n);
	bool ok = 0;
	if(y < k)
		st = k-y;
	else
		st = ceil(y/(double)k)*k - y;
	if(st == 0) st = k;
	for(ll x = st; x+y <= n; x += k) {
		if(!ok) {
			pf("%lld", x);
			ok = 1;
		}
		else
			pf(" %lld", x);
	}
	
	if(!ok)
		pf("-1\n");
	else
		pf("\n");
	return 0;
}
