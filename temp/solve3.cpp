// Codeforces
// A. Eugeny and Array
// http://codeforces.com/problemset/problem/302/A

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
#define All(x) x.begin(), x.end()
#define fr(i, a, b) for(register int i = (a); i < (int)(b); i++)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbg(vari) cerr << #vari << " = " << (vari) <<endl
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

int v[200010] = {0};

int main() {
	int n, q, c[3]={0}, x;
	sf("%d %d", &n, &q);
	fr(i, 0, n) {
		sf("%d", &x);
		x+=1;
		c[x]++;
		int t = min(c[0], c[2]);
		//cout << " c " << c[0] << " " << c[2] << " " << t+t << endl;
		if(t != 0)
			v[t+t] = 1;
	}
	
	int l, r;
	fr(i, 0, q) {
		sf("%d %d", &l, &r);
		if(v[r-l+1] != 0)
			pf("1\n");
		else
			pf("0\n");
	}
	
	return 0;
}
