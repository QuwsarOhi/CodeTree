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
	int n,x,l=-1,r=-1,mid=-1,cnt = 0;
	sf("%d", &n);
	vii v;
	fr(i, 0, n) {
		sf("%d", &x);
		v.pb({x, i});
	}
	sort(v.begin(), v.end());
	bool ok = 1;
	fr(i, 0, n) {
		//pf("i : %d l : %d r : %d mid : %d fi : %d se : %d ok : %d : %d\n", i, l, r, mid, v[i].fi, v[i].se, ok, r-v[i].se);
		if(v[i].se == i) {
			++cnt;
			continue;
		}
		else if(v[i].se != i && l == -1)
			r = l = v[i].se;
		else {
			if(r-v[i].se == 1)
				r = v[i].se;
			else if(r-v[i].se == 2)
				r = v[i].se, mid = v[i-1].se;
			else
				ok = 0;
		}
	}
	
	if(cnt == n)
		pf("yes\n1 1\n");
	else if(l == -1 || ok == 0 || (mid!= -1 && mid != (l+r)/2))
		pf("no\n");
	else
		pf("yes\n%d %d\n", r+1, l+1);
		
	return 0;
}
