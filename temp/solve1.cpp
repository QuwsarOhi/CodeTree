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

// x, h

struct node {
    ll sX, sH, eX, eH, sum;
};

node tree[MAX*5];
ll h[MAX], x[MAX];

ll add(node lft, node rht) {
    ll dist = rht.sX - lft.eX;
    if(dist <= lft.eH)
        return 0;
    return dist - lft.eH;
}

node merge(node lft, node rht) {
    node tmp;
    tmp.sX = lft.sX, tmp.sH = lft.sH;
    tmp.eX = rht.eX, tmp.eH = rht.eH;
    tmp.sum = lft.sum + rht.sum + add(lft, rht);
    return tmp;
}


void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos].sX = tree[pos].eX = x[l];
        tree[pos].sH = tree[pos].eH = h[l];
        tree[pos].sum = 0;
        return;
    }
    //printf("segment %d %d\n", l, r);
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    tree[pos] = merge(tree[pos<<1], tree[pos<<1|1]);
    //tree[pos].sum += add(tree[pos<<1], tree[pos<<1|1]);
}


node query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l) {
        node tmp;
        tmp.sX = tmp.eX = tmp.sH = tmp.eH = tmp.sum = 0;
        return tmp;
    }
    
    if(L <= l && r <= R) {
        //printf("ret segment %d %d : %lld\n", l, r, tree[pos].sum);
        return tree[pos];
    }
    
    int mid = (l+r)>>1;
    
    node lft = query(pos<<1, l, mid, L, R);
    node rht = query(pos<<1|1, mid+1, r, L, R);
    
    if(lft.sX == 0)
        return rht;
    else if(rht.sX == 0)
        return lft;
    
    //printf("added %d %d + %d %d : %lld\n", l, mid, mid+1, r, add(lft, rht));
    
    node tmp = merge(lft, rht);
    return tmp;
}


int main() {
    int n, q, l, r;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld%lld", &x[i], &h[i]);
    
    scanf("%d", &q);
    init(1, 1, n);
    
    while(q--) {
        scanf("%d%d", &l, &r);
        printf("%lld\n", query(1, 1, n, l, r).sum);
    }
    
    return 0;
}
