// Codeforces
// C. Palindrome Transformation
// http://codeforces.com/problemset/problem/486/C
// Greedy

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

int n, p, ans;

int cal(int start, vector<int> &v) {
	int ans1 = 0, ans2 = 0, lst = start;
	for(int i = 0; i < (int)v.size(); ++i) {
		ans1 += abs(lst-v[i]);
		lst = v[i];
	}
	lst = start;
	for(int i = v.size()-1; i >= 0; --i) {
		ans2 += abs(lst-v[i]);
		lst = v[i];
	}
	return min(ans1, ans2);
}

int main() {
	char s[100010];
	vi v1, v2;
	sf("%d %d", &n, &p);
	--p;
	fr(i, 0, n)
		sf(" %c", &s[i]);
	for(int i = 0, j = n-1; i < j; ++i, --j)
		if(s[i] != s[j]) {
			ans += min(abs(s[i]-s[j]+26)%26, abs(s[j]-s[i]+26)%26);
			v1.pb(i), v2.pb(j);
		}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	pf("%d\n", ans+min(cal(p, v1), cal(p, v2)));
	return 0;
}
