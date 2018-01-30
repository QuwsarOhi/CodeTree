#include <bits/stdc++.h>
using namespace std;
#define MAX                 50
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


int level[MAX];
int sparse[MAX][20];
int parent[MAX];

vi G[MAX];

void dfs(int u, int pst, int l) {
    parent[u] = pst;
    level[u] = l;
    
    for(auto v : G[u])
        if(parent[u] != v)
            dfs(v, u, l+1);
}

int LCA(int u, int v) {
    if(level[u] > level[v])
        swap(u, v);
    
    // u top, v down
    //for(p = 1; level[v] > (1<<p); ++p);             // max 
    
    int p = ceil(log2(level[v]));
    for( ; p >= 0; --p)
        if(level[v] - (1LL<<p) >= level[u])
            v = sparse[v][p];
    
    if(v == u)
        return v;
    
    for( ; p >= 0; --p)
        if(sparse[v][p] != -1 && sparse[v][p] != sparse[u][p])
            v = sparse[v][p], u = sparse[u][p];
    
    return parent[v];
}


void LCAinit(int N) {
    memset(sparse, -1, sizeof sparse);
    
    for(int u = 0; u <= N; ++u)              // first parent of every node u
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1LL<<p) <= N; ++p)
        for(int u = 0; u <= N; ++u)
            if((v = sparse[u][p-1]) != -1)
                sparse[u][p] = sparse[v][p-1];

}

int main() {
    G[0].pb(1);
	G[0].pb(2);
	G[2].pb(3);
	G[2].pb(4);
    G[4].pb(5);
	dfs(0, 0, 0);
	LCAinit(6);
	printf( "%d\n", LCA(3,5));
    return 0;
}
