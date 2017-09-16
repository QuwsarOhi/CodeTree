// Codeforces
// A. Curriculum Vitae
// http://codeforces.com/contest/846/problem/A

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
	int n, mx = 0, one[110] = {0}, zero[110] = {0}, v[110];
	sf("%d", &n);
	fr(i, 0, n)
		sf("%d", &v[i]);
	
	one[n-1] = v[n-1];
	for(int i = n-2; i >= 0; --i)
		one[i] = one[i+1] + v[i];
		
	zero[0] = (v[0] == 0);
	
	for(int i = 1; i < n; ++i)
		zero[i] = zero[i-1] + (v[i] == 0);
	
	for(int i = 0; i < n; ++i)
		mx = max(mx, zero[i]+one[i+1]);
	
	pf("%d\n", max(mx, one[0]));
	return 0;
}
