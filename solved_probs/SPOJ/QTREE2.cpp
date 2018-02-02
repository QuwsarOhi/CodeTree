// SPOJ QTREE2

#include <bits/stdc++.h>
using namespace std;
#define MAX                 20000
#define EPS                 1e-9
#define INF                 1000000000
#define MOD                 1000003
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//---------------------------------------------------------------------------------------------------------

vl G[MAX], W[MAX];
int level[MAX], parent[MAX], sparse[MAX][20];
ll dist[MAX];


void LCAinit(int V) {
    memset(sparse, -1, sizeof sparse);
    
    for(int u = 1; u <= V; ++u)                 // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1LL<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}


int LCA(int u, int v) {
    if(level[u] > level[v])     // v is deeper
        swap(u, v);
    
    int p = ceil(log2(level[v]));
    
    // Pull up v to same level as u
    for(int i = p ; i >= 0; --i)
        if(level[v] - (1LL<<i) >= level[u])
            v = sparse[v][i];
    
    // if u WAS the parent
    if(u == v)
        return u;
    
    // Pull up u and v together while LCA not found
    for(int i = p; i >= 0; --i)
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    
    //cout << "lcs:: " << parent[u] << endl;
    return parent[u];
}

void dfs(int u, int par, int lvl, ll d) {
    level[u] = lvl;
    parent[u] = par;
    dist[u] = d;
    
    for(int i = 0; i < SIZE(G[u]); ++i)
        if(parent[u] != G[u][i])
            dfs(G[u][i], u, lvl+1, d+W[u][i]);
}


ll Distance(int u, int v) {
    int lca = LCA(u, v);
    return dist[v] + dist[u] - 2*dist[lca];
}

int KthNode(int u, int v, int k) {              // Main Problem
    int lca = LCA(u, v);
    bool sameChain = (lca == v) || (lca == u);
    
    
    //error(u, v, lca, level[u], level[v], level[lca], k);
    
    if(sameChain) {
        if(lca == u) {
            k = level[v]-level[u]+2-k;
            swap(u,v);
        }
    }
    else {
        if(level[u]-level[lca]+1 < k) {
            k = level[u]+level[v]-2*level[lca]-k+2;
            swap(u, v);
        }
    }
    
    // We need to pull node u : k steps up
    --k;
    //cout << "K " << k << endl;
    for(int i = ceil(log2(level[u])); i >= 0; --i)
        if((1<<i) <= k) {
            u = sparse[u][i];
            k -= (1<<i);
        }

    return u;
}

int main() {
    //fileRead("in");
    //fileWrite("out2");
    ll t, u, v, k, w, V;
    char s[10];
    
    sf("%lld", &t);
    //pf("testcase %lld\n", t);
    while(t--) {
        sf("%lld", &V);
        //cout << "V " << V << endl;
        for(int i = 0; i < V-1; ++i) {
            sf("%lld %lld %lld", &u, &v, &w);
            G[u].pb(v);
            G[v].pb(u);
            W[u].pb(w);
            W[v].pb(w);
        }
        
        memset(dist, 0, sizeof dist);
        memset(parent, -1, sizeof parent);
        dfs(1, -1, 0, 0);
        LCAinit(V);
        
        while(1) {
            sf("%s", s);
            if(s[1] == 'O')
                break;
            
            if(s[0] == 'K') {
                sf("%lld%lld%lld", &u, &v, &k);
                pf("%d\n", KthNode(u, v, k));
            }
            else {
                sf("%lld%lld", &u, &v);
                //cout << "DIS" << u << " " << v << endl;
                pf("%lld\n", Distance(u, v));
            }
        }
        
        for(int i = 0; i <= V; ++i)
            G[i].clear(), W[i].clear();
    }
    
    return 0;
}
