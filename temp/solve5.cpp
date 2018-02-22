#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
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
		prefix = max(left.prefix, left.sum+right.prefix);
		suffix = max(right.suffix, right.sum+left.suffix);
		sum = left.sum + right.sum;
		ans = max(left.ans, max(right.ans, left.suffix+right.prefix));
	}
};

node tree[600000];
ll ans[110000], IDX[220000], CONST = 101000, val[110000];
set<pair<pii, int> >Query;

void update(int pos, int l, int r, int idx, int val) {
    if(l == r) {
        tree[pos] = node(val);
        return;
    }
    
    int mid = (l+r)>>1;
    
    if(idx <= mid)
        update(pos<<1, l, mid, idx, val);
    else
        update(pos<<1|1, mid+1, r, idx, val);
    
    tree[pos].merge(tree[pos<<1], tree[pos<<1|1]);
}


node query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return node(0);
    
    if(L <= l && r <= R)
        return tree[pos];
    
    int mid = (l+r)>>1;
    
    node x = query(pos<<1, l, mid, L, R);
    node y = query(pos<<1|1, mid+1, r, L, R);
    
    node tmp = node(0);
    tmp.merge(x, y);
    
    return tmp;
}


int main() {
    fileRead("in");
    fileWrite("out");
    
    int n, q, l, r;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    
    scanf("%d", &q);
    
    for(int i = 1; i <= q; ++i) {
        scanf("%d%d", &l, &r);
        Query.insert({{r, l}, i});
    }
    
    //for(int i = 0; i < 600000; ++i)
    //    tree[i] = node(0);
    
    int pos = 1;
    memset(IDX, -1, sizeof IDX);
    
    for(auto it : Query) {
        l = it.first.second;
        r = it.first.first;
        //printf("%d At Query %d %d\n", it.second, l, r);
        
        while(pos <= r) {
            if(IDX[val[pos]+CONST] != -1) {
                //printf("Remove %d from %d\n", val[pos], IDX[val[pos]+CONST]);
                update(1, 1, n, IDX[val[pos]+CONST], 0);
            }
            
            //printf("Adding %d at %d\n", val[pos], pos);
            IDX[val[pos]+CONST] = pos;
            update(1, 1, n, pos, val[pos]);
            pos++;
        }
        
        ans[it.second] = max(query(1, 1, n, l, r).ans, 0LL);
        //printf("Ans : %d\n", ans[it.second]);
    }
    
    for(int i = 1; i <= q; ++i)
        printf("%lld\n", ans[i]);
    
    return 0;
}
