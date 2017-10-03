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

// 0 0 0
// 0 0 4
// 0 4 4
// 0 2 4
// 0 3 12
// 1 3 12
// 3 3 3
// 1 2 3


int main() {
	ll a[3], x;
	
	sf("%lld %lld %lld", &a[0], &a[1], &a[2]);
	
	sort(a, a+3);
	x = (a[0]+a[1]+a[2])/3;

	if(a[0] == 0 && a[1] == 0)
		x = 0;
	else if(a[0] == 0)
		x = min(x, a[1]);
	else
		x = min(x, a[1]+a[0]);

	pf("%lld\n", x);
	
	return 0;
}
