#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-2
#define INF                 0x3f3f3f3f
#define MOD					1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

ll n, k;
bool vis[1000];

ll recur(int pos, ll sum) {
	//cerr << pos << " " << sum << endl;

	if(sum < 0) 	return -1;
	if(pos == k-1) 	{
		if(vis[sum] or sum == 0)
			return -1;
		return (sum*sum - sum);
	}
	if(sum == 0) return -1;

	ll ret = -1;
	for(ll i = 1; i <= sum; ++i) {
		if(vis[i]) continue;
		vis[i] = 1;
		ll tmp = recur(pos+1, sum-i);
		if(tmp != -1) {
			ret = max(ret, tmp*(i*i-i));
		}
		vis[i] = 0;
	}
	return ret;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		cin >> n >> k;
		cout << recur(0, n) << endl;
	}
	return 0;
}