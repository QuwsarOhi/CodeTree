#include <bits/stdc++.h>
using namespace std;
#define MAX                 1100
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

struct STree {
    ll mx[4*MAX];
    
    void init(int pos, int l, int r, ll v[]) {
        if(l == r) {
            mx[pos] = v[l];
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, v);
        init(pos<<1|1, mid+1, r, v);
        mx[pos] = max(mx[pos<<1], mx[pos<<1|1]);
        //cerr << "ST " << pos << " : " << mx[pos] << endl;
    }
    
    void update(int pos, int l, int r, int idx, int val) {
        if(l == r) {
            mx[pos] += val;
            return;
        }
        int mid = (l+r)>>1;
        if(idx <= mid)
            update(pos<<1, l, mid, idx, val);
        else
            update(pos<<1|1, mid+1, r, idx, val);
        mx[pos] = max(mx[pos<<1], mx[pos<<1|1]);
    }
    
    ll query() {
        return mx[1];
    }
}ST;

ll MXLVL, lvlSum[MAX], W[MAX], lvlErased[MAX], ans[MAX], LVL[MAX];
vector<int>G[MAX];
vl NODES[MAX];

void levelSum(int u, int par = -1, ll lvl = 1) {
    lvlSum[lvl] += W[u];
    LVL[u] = lvl;
    NODES[u].push_back(u);
    for(auto v : G[u])
        if(v != par) {
            levelSum(v, u, lvl+1);
            NODES[u].reserve(NODES[u].size()+NODES[v].size());
            NODES[u].insert(NODES[u].end(), NODES[v].begin(), NODES[v].end());
        }
    MXLVL = max(lvl, MXLVL);
}

void ERASEALL(int u) {
    for(auto x : NODES[u])
        ST.update(1, 1, MXLVL, LVL[x], -W[x]);
}

void ADDALL(int u) {
    for(auto x : NODES[u])
        ST.update(1, 1, MXLVL, LVL[x], W[x]);
} 

void dfs(int u, int par = -1, int lvl = 1) {
    for(auto v : G[u])
        if(v != par)
            dfs(v, u, lvl+1);
    ERASEALL(u);
    ans[u-1] = ST.query();
    ADDALL(u);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, V, p;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &V);
        
        for(int i = 1; i <= V; ++i)
            scanf("%lld", &W[i]);
        
        // Root is always 1

        for(int c = 2; c <= V; ++c) {
            scanf("%d", &p);
            G[p].push_back(c);
            G[c].push_back(p);
        }
        
        MXLVL = -1;
        memset(lvlSum, 0, sizeof lvlSum);
        memset(lvlErased, 0, sizeof lvlErased);
        levelSum(1, -1, 1);
        
        //for(int i = 1; i <= MXLVL; ++i)
        //    printf("%lld ", lvlSum[i]);
        //printf("\n");
        
        ST.init(1, 1, MXLVL, lvlSum);
        dfs(1, -1, 1);
        
        for(int i = 1; i < V; ++i)
            printf("%lld\n", ans[i]);
            
        // CLEAR GRAPH
        for(int i = 0; i <= V; ++i) G[i].clear(), NODES[i].clear();
    }
    return 0;
}
