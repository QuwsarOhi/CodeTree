// SPOJ - GSS5 - Can you answer these queries V
// http://www.spoj.com/problems/GSS5/

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e9
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

struct node {
	ll ans, prefix, suffix, sum;
	
	node(int val = 0) {
		ans = prefix = suffix = sum = val;
	}
	
	void merge(node left, node right) {
		this->prefix = max(left.prefix, left.sum+right.prefix);
		this->suffix = max(right.suffix, right.sum+left.suffix);
		this->sum = left.sum + right.sum;
		this->ans = max(left.ans, max(right.ans, left.suffix+right.prefix));
	}
};

node tree[200100];
ll val[50100];

void init(int pos, int l, int r) {
	if(l == r) {
		tree[pos] = node(val[l]);
		return;
	}
	
	int mid = (l+r)/2;
	
	init(pos*2, l, mid);
	init(pos*2+1, mid+1, r);
	
	tree[pos].merge(tree[pos*2], tree[pos*2+1]);
}


node query(int pos, int l, int r, int x, int y) {
	if(r < x || y < l) {
        node tmp = node(-INF);
        tmp.sum = 0;
        return tmp;
    }
	
	if(x <= l && r <= y)
		return tree[pos];
	
	int mid = (l+r)/2;
	
	node lft = query(pos*2, l, mid, x, y);
	node rht = query(pos*2+1, mid+1, r, x, y);
    
	node parent = node();
	parent.merge(lft, rht);
	return parent;
}


int main() {
    ll t, x1, x2, y1, y2, q, ans, n;
    
    scanf("%lld", &t);
    
    while(t--) {
        scanf("%lld", &n);
        
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &val[i]);
        
        init(1, 1, n);
        
        
        
        scanf("%lld", &q);
        
        while(q--) {
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            
            if(y1 < x2) {
                ans = query(1, 1, n, x1, y1).suffix;
                ans += query(1, 1, n, x2, y2).prefix;
                ans += query(1, 1, n, y1+1, x2-1).sum;
            }
            else {
                ans = query(1, 1, n, x1, x2-1).suffix + query(1, 1, n, x2, y2).prefix;
                ans = max(ans, query(1, 1, n, x2, y1).suffix + query(1, 1, n, y1+1, y2).prefix);
                ans = max(ans, query(1, 1, n, x2, y1).ans);
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}
