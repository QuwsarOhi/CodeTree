#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define pf                  printf
#define sf(XX)              scanf("%d", &XX)
#define sfll(XX)            scanf("%lld", &XX)
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileR(S)            freopen(S, "r", stdin);
#define FileW(S)            freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define STOLL(X)            stoll(X, 0, 0)

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

int nextNode[MAX], chain[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], Ans[MAX], parent[MAX], Edge[MAX];
int ChainNo = 1, all = 1, n;
vi G[MAX];

priority_queue<int>pq;
priority_queue<pii>Rpq;

void dfs(int u, int Parent) {
    parent[u] = Parent;
    ChainSize[u] = 1;
    
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent)
            continue;
            
        dfs(v, u);
        //ChainSize[u] += ChainSize[v];
        
        if(nextNode[u] == -1 || ChainSize[v] > ChainSize[nextNode[u]])
            nextNode[u] = v;
    }
    
    if(nextNode[u] != -1)
        ChainSize[u] += ChainSize[nextNode[u]];
}

void hld(int u, int Parent) {
    chain[u] = ChainNo;
    
    //cout << u << " : " << ChainNo << endl;
    
    if(ChainSize[ChainNo] == 0)
        top[ChainNo] = u;
        
    ChainSize[ChainNo]++;
    
    if(nextNode[u] != -1)
        hld(nextNode[u], u);
    
    for(int i = 0; i < SIZE(G[u]); ++i) {
        int v = G[u][i];
        if(v == Parent || v == nextNode[u])
            continue;
        ChainNo++;
        hld(v, u);
    }
}

int root = -1, mxlvl = -1;

void FindRoot(int u, int par, int lvl) {
    bool leaf = 1;
    
    for(auto v : G[u])
        if(v != par) {
            leaf = 0;
            FindRoot(v, u, lvl+1);
        }
    
    if(leaf and lvl > mxlvl) {
        mxlvl = lvl;
        root = u;
    }
}
    
int main() {
    int n, u, v;
    sf(n);
    
    for(int i = 1; i < n; ++i) {
        sf(u), sf(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    
    FindRoot(1, -1, 0);
    memset(nextNode, -1, sizeof nextNode);
    ChainNo = 1, all = 1;
    dfs(root, -1);
    memset(ChainSize, 0, sizeof ChainSize);
    hld(root, -1);
    
    //cout << "ROOT " << root << endl;
    
    for(int i = 1; i <= ChainNo; ++i)
        pq.push(ChainSize[i]);
        
    for(int i = 2; i <= n; ++i) {
        Ans[i] += Ans[i-1];
        
        if(!pq.empty()) {
            Ans[i] += pq.top();
            pq.pop();
        }
    }
    Ans[1] = 1;
    
    for(int i = 1; i <= n; ++i) {
        pf("%d", Ans[i]);
        if(i != n) pf(" ");
    }
    pf("\n");
    
    return 0;
}
