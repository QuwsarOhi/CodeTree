// UVa
// 259 - Software Allocation

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


int G[40][40], parent[40], totFlow = 0;
vi edge[40];


bool bfs(int s, int t) {
    memset(parent, -1, sizeof parent);
    parent[s] = -1;
    queue<int>q;
    q.push(s);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(auto v : edge[u])
            if(G[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                if(v == t)
                    return 1;
                q.push(v);
            }
    }
    
    return 0;
}

int maxFlow(int s, int t) {
    int max_flow = 0;
    memset(parent, -1, sizeof parent);
    
    while(bfs(s, t)) {
        int flow = INT_MAX;
        
        for(int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, G[u][v]);
        }
        
        for(int v = t; v != s;  v = parent[v]) {
            int u = parent[v];
            G[u][v] -= flow;
            G[v][u] += flow;
        }
        max_flow += flow;
    }
    
    return max_flow;
}


void printer(int source, int dest) {
    // Connect right nodes (computers) with sink
    for(char c = '0'; c <= '9'; ++c) {
        int u = c-'0'+27;
        edge[u].pb(dest);
        G[u][dest] = 1;
    }
            
    // Check the answer
    int flow = maxFlow(source, dest);
    if(flow == totFlow) {
        for(int u = 27; u <= 36; ++u) {
            bool found = 0;
            for(int v = 1; v <= 26; ++v)
                if(G[u][v]) {
                    pf("%c", v+'A'-1);
                    found = 1;
                    break;
                }
            if(!found)
                pf("_");
        }
        pf("\n");
    }
    else
        pf("!\n");
            
    // Clear All
    totFlow = 0;
    memset(G, 0, sizeof G);
    for(int i = 0; i < 40; ++i)
        edge[i].clear();
}

int main() {
    FastRead;
    string s1;
    
    while(getline(cin, s1)) {
        if(s1.empty()) {                // Newline process
            printer(0, 37);
            continue;
        }
        
        int u = s1[0]-'A'+1;
        int w = s1[1]-'0';
        
        edge[0].pb(u);
        G[0][u] += w;                               // source to node(Applications)
        totFlow += w;                               // number of user
        for(int i = 3; i < SIZE(s1)-1; ++i) {       // Application to Computer
            int v = s1[i]-'0'+27;
            edge[u].pb(v);
            edge[v].pb(u);
            G[u][v] = 1;
        }
    }
    
    printer(0, 37);
    return 0;
}
        
