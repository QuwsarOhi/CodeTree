// Codeforces
// A. Inna and Pink Pony
// http://codeforces.com/contest/374/problem/A
// Math

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
	int n, m, mn = INF, i, j, a, b;
	sf("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b);
	int X[] = {1, 1, n, n}, Y[] = {1, m, 1, m};
	int dx = i%a, dy = j%b;
	fr(p, 0, 4) {
		if(X[p]%a == dx && Y[p]%b == dy) {
			int x = abs(X[p]-i), y = abs(Y[p]-j);
			if(x%a != 0 || y%b != 0)
				continue;
			if((x/a)%2 != (y/b)%2)
				continue;
			mn = min(max(x/a, y/b), mn);
		}
	}
	
	if(mn == INF || ((a >= n || b >= m) && mn != 0))
		pf("Poor Inna and pony!\n");
	else
		pf("%d\n", mn);
		
	return 0;
}
