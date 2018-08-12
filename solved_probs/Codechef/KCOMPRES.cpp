// CodeChef
// https://www.codechef.com/AUG18B/problems/KCOMPRES

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
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

inline void fastIn(ll &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register int c;
    num = 0;
    c = getchar();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}

struct RangeMax {
	ll tree[4*MAX];
	void init(int pos, int l, int r) {
		tree[pos] = 0;
		if(l == r) return;
		int mid = (l+r)>>1;
		init(pos<<1, l, mid), init(pos<<1|1, mid+1, r);
	}
	ll query(int pos, int l, int r, int L, int R) {
		if(r < L or R < l) return 0;
		if(L <= l and r <= R) return tree[pos];
		int mid = (l+r)>>1;
		return max(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
	}
	void update(int pos, int l, int r, int idx, ll val) {
		if(l == r) {
			tree[pos] = val;
			return;
		}
		int mid = (l+r)>>1;
		if(idx <= mid) 	update(pos<<1, l, mid, idx, val);
		else 			update(pos<<1|1, mid+1, r, idx, val);
		tree[pos] = max(tree[pos<<1], tree[pos<<1|1]);
	}
	ll queryRange(int pos, int n, int k) {
		int l = max(1, pos-k), r = min(n, pos+k);
		if(l == r) return 0;
		return query(1, 1, n, l, r);
}};
		
RangeMax st;
ll a[MAX];
ll GO[MAX];

ll assigned[MAX];
map<ll, vector<ll> >MAP;
ll sum;

void FixPast(ll p1) {
	if(GO[p1] == -1) return;
	ll p2 = GO[p1];
	if(assigned[p1] != assigned[p2]) {
		//cerr << "GONE " << p1 << " to " << p2 << "FIXED\n";
		sum -= assigned[p2];
		sum += assigned[p1];
		assigned[p2] = assigned[p1];
		FixPast(p2);
	}
}

ll simulate(ll k, ll n) {
	sum = 0;
	st.init(1, 1, n);
	memset(GO, -1, sizeof GO);
	memset(assigned, 0, sizeof assigned);
	
	for(auto vv : MAP) {
		vl v = vv.se;
		for(int i = 0; i < (int)v.size(); ++i) {
			bool inRange = 0;
			if(i) {
				ll pstR = min((ll)n, v[i-1]+k);
				if(pstR >= v[i]) {						// In Range and Same
					inRange = 1;
					GO[v[i]] = v[i-1];
					//cerr << "linked\n";
				}
			}
			
			ll val = st.queryRange(v[i], n, k);
			if(inRange)
				val = max(val+1, assigned[v[i-1]]);
			else
				val++;
				
			//cerr << " new " << val << endl;
			assigned[v[i]] = val;
			sum += val;
			FixPast(v[i]);
			//st.update(1, 1, n, v[i], assigned[v[i]]);
		}
		
		for(int i = 0; i < (int)v.size(); ++i)
			st.update(1, 1, n, v[i], assigned[v[i]]);
	}
	
	/*cerr << k << " : ";
	ll ss = 0;
	for(int i = 1; i <= n; ++i) {
		ss += assigned[i];
		cerr << assigned[i] << " ";
	}
	cerr << ": " << ss << endl;*/
	return sum;
}
		
int main() {
	//fileRead("in");
	//fileWrite("out");
	
	ll s, n, t;
	sf("%lld", &t);
	while(t--) {
		sf("%lld%lld", &n, &s);
		MAP.clear();
		for(int i = 1; i <= n; ++i) {
			sf("%lld", &a[i]);
			MAP[a[i]].pb(i);
		}
		ll ans = 0;
		ll lo = 0, hi = n;
		while(lo <= hi) {
			ll mid = (lo+hi)>>1;
			if(simulate(mid, n) <= s) {
				ans = max(ans, mid+1);
				lo = mid+1;
			}
			else
				hi = mid-1;
		}
		
		/*cerr << "GOT " << ans << endl;
		for(int k = 0; k <= n; ++k) {
			if(simulate(k, n) <= s)
				ans = k+1;
			//else
			//	break;
		}*/
		
		pf("%lld\n", ans);
	}
	return 0;
}

/*

1
8 23
4 2 8 1 4 3 8 1
4

1
8 20
4 2 2 1 4 3 8 1
3

5 10
0 2 1 0 6
3

5 9
0 2 1 0 6
2

5 1
0 2 1 0 6
0

1
9 50
4 2 1 2 1 4 3 8 1

1
8 100
4 2 8 1 4 3 8 1

1
8 20
4 2 2 1 4 3 8 1 

1
8 20
1 8 3 4 1 2 2 4

*/
