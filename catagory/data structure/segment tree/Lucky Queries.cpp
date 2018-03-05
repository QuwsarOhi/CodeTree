// CodeFroces
// http://codeforces.com/problemset/problem/145/E
// Lucky Queries

#include <bits/stdc++.h>
using namespace std;
#define MAX                 1100000
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
    int n47, n4, n7, n74;
    bool prop;
    
    node(int val=0) {
        n74 = n47 = n4 = n7 = 0;
        prop = 0;
        if(val == 4)
            n4 = n47 = 1;
        else if(val == 7)
            n7 = n74 = 1;
    }
    
    void Merge(node lft, node rht) {
        n4 = lft.n4 + rht.n4;
        n7 = lft.n7 + rht.n7;
        n47 = max(lft.n47 + rht.n7, lft.n4 + rht.n47);
        n74 = max(lft.n74 + rht.n4, lft.n7 + rht.n74);
    }
};

char qt[10], val[MAX];
node tree[MAX*5];

void SwapNode(int pos) {
    swap(tree[pos].n4, tree[pos].n7);
    swap(tree[pos].n47, tree[pos].n74);
    tree[pos].prop ^= 1;
}

void propagate(int pos, int l, int r) {
    if(!tree[pos].prop || l == r)
        return;
        
    SwapNode(pos<<1);
    SwapNode(pos<<1|1);
    tree[pos].prop = 0;
}


void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos] = node(val[l]);
        return;
    }
    
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    tree[pos].Merge(tree[pos<<1], tree[pos<<1|1]);
}

void update(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        SwapNode(pos);
        return;
    }
    
    int mid = (l+r)>>1;
    update(pos<<1, l, mid, L, R);
    update(pos<<1|1, mid+1, r, L, R);
    
    tree[pos].Merge(tree[pos<<1], tree[pos<<1|1]);
}


int main() {
    int n, q, l, r;

    scanf("%d%d", &n, &q);
    
    for(int i = 1; i <= n; ++i) {
        scanf(" %c", &val[i]);
        val[i] -= '0';
    }
    
    init(1, 1, n);
    
    while(q--) {
        scanf(" %s", qt);
        
        if(qt[0] == 'c')
            printf("%d\n", max(tree[1].n47, max(tree[1].n4, tree[1].n7)));
        else {
            scanf("%d%d", &l, &r);
            update(1, 1, n, l, r);
        }
    }
    
    return 0;
}
