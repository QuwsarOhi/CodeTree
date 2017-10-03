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

int n, m, cnt[110] = {0};

int main() {
	vector<string>v;
	unordered_map<char, bool>used[110];
	cin >> n >> m;
	string x;
	fr(i, 0, n) {
		cin >> x;
		fr(i, 0, x.size())
			if(used[i].find(x[i]) == used[i].end()) {
				used[i][x[i]] = 1;
				cnt[i]++;
			}
	}
	
	ll ans = 1;
	fr(i, 0, m)
		ans = (ans * cnt[i])%MOD;
		
	cout << ans << endl;
	
	return 0;
}
