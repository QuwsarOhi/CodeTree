#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
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

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
#define EPS                 1e-9
#define INF                 1e7
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


vector<int>G[600], SCC;
int dfs_num[600], dfs_low[600], dfsCounter, SCC_no = 0, Indegree[600];
bitset<600>visited;

void tarjanSSC(int u, int ignore) {
    //Stack, here, it is implemented as vector instead
    SCC.push_back(u);
    //Marking node u as visited
    //visited[u] marks if the node u is usable in a SCC and not used on other SCC
    //if visited[u] is false, then it is used in other SCC
    visited[u] = 1;
    
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    //for all Strongly Connected Component (directed graph), dfs_low[u] is same
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == ignore)
            continue;
        //if it is not visited yet, backtrack it
        if(dfs_num[v] == 0)
            tarjanSSC(v, ignore);

        // visited[v] is used to check if this node is not in any other SCC
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    //in a SCC the first node of the SCC, node u is the first node in a SCC if dfs_low[u] == dfs_low[v]
    //as we implementing stack like data structure, the nodes from top to u are on the same SCC
    if(dfs_low[u] == dfs_num[u]) {
        SCC_no++;       // Component Node no. starts from 0
        while(1) {
            int v = SCC.back();
            SCC.pop_back();

            //node v is used, so marking it as false, so that the ancestor nodes
            //doesn't use this node to update it's value
            
            visited[v] = 0;
            //printf("%d\n", v);
            //Component[v] = SCC_no;      // Marking SCC nodes to as same component
            if(u == v)
                break;
        }
        //printf("\n");
    }
}

void init() {
    memset(dfs_num, 0, sizeof(dfs_num));
    dfsCounter = 0;
    visited.reset();
    SCC_no = 0;
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    FastRead;
    int n, m, u, v;
    vi ones;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u].pb(v);
        Indegree[v]++;
    }
    
    for(int i = 1; i <= n; ++i) {
        if(Indegree[i] == 1)
            ones.pb(i);
    }
    
    init();
    for(int i = 1; i <= n; ++i)
        if(dfs_num[i] == 0)
            tarjanSSC(i, 0);
    
    if(SCC_no == n) {
        cout << "YES\n";
        return 0;
    }
    
    for(auto it : ones) {
        init();
        //cout << "IGNORE " << it << endl;
        for(int i = 1; i <= n; ++i)
            if(dfs_num[i] == 0)
                tarjanSSC(i, it);
        if(SCC_no == n) {
            cout << "YES\n";
            return 0;
        }
        //cout << SCC_no << endl;
    }
    
    cout << "NO\n";
    return 0;
}
