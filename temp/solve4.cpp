// CodeForces
// D. Destiny
// http://codeforces.com/contest/840/problem/D

// Find value that occurs STRICTLY greater than k times in a given range [L, R]

#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
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
    int val;
    node *lft, *rht;
    
    node(node *L = NULL, node *R = NULL, int v = 0) {
        lft = L;
        rht = R;
        val = v;
    }
};

node *presis[301000], *null = new node();

node *nCopy(node *x) {
    node *tmp = new node();
    if(x) {
        tmp->val = x->val;
        tmp->lft = x->lft;
        tmp->rht = x->rht;
    }
    return tmp;
}


// Single Position update
void insert(node *pos, ll l, ll r, ll idx) {
    if(l == r) {
        pos->val++;
        pos->lft = null;
        pos->rht = null;
        return;
    }
    
    ll mid = (l+r)>>1;
    
    if(idx <= mid) {
        pos->lft = nCopy(pos->lft);
        if(pos->rht == NULL)
            pos->rht = null;
        insert(pos->lft, l, mid, idx);
    }
    else {
        pos->rht = nCopy(pos->rht);
        if(pos->lft == NULL)
            pos->lft = null;
        insert(pos->rht, mid+1, r, idx);
    }
    
    pos->val++;
}


int query(node *RMax, node *LMax, int l, int r, int k) {                         // (LMax : past, RMax : updated)
    int Count = RMax->val - LMax->val;
    
    //printf("%d ---- %d :: %d [%d %d]\n", l, r, Count, RMax->val, LMax->val);
    
    // Search for the minimum val where Count is STRICTLY greater than k
    
    // Almost like binary search??
    
    if(Count <= k)
        return -1;
    
    if(l == r)
        return l;
    
    int mid = (l+r)>>1, ret = -1;
    
    if(RMax->lft && LMax->lft)                          // if we can go lft and it is valid
        ret = query(RMax->lft, LMax->lft, l, mid, k);
    
    if(ret == -1 && RMax->rht && LMax->rht)             // if we didnt find answer and we can go rhight and its also valid
        ret = query(RMax->rht, LMax->rht, mid+1, r, k);
    
    return ret;
}

int main() {
    int n, q, l, r, k, val, lim = 300000, pos;
    
    scanf("%d%d", &n, &q);
    null->lft = null->rht = null;
    presis[0] = new node();
    
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        presis[i] = nCopy(presis[i-1]);
        insert(presis[i], 1, lim, val);
    }
    
    
    while(q--) {
        scanf("%d%d%d", &l, &r, &k);
        
        if(l == 1)
            pos = query(presis[r], null, 1, lim, (r-l+1)/k);            // (r-l+1)/k is the given value which is the number of occurance
        else
            pos = query(presis[r], presis[l-1], 1, lim, (r-l+1)/k);
        printf("%d\n", pos);
    }
    
    return 0;
}
