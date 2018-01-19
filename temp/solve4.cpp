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


int G[40][40], parent[40], cnt;
vi edge[40];
bitset<40>vis;
map<int, char>toChar;
map<char, int>toInt;
map<char, char>Map;

int toNode(char x) {
    if(toInt.find(x) == toInt.end()) {
        toInt[x] = ++cnt;
        toChar[cnt] = x;
        return cnt;
    }
    return toInt[x];
}

char nodeChar(int x) {
    return toChar[x];
}

bool bfs(int s, int t) {
    vis.reset();
    //memset(parent, -1, sizeof parent);
    parent[s] = -1;
    vis[s] = 1;
    queue<int>q;
    q.push(s);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(auto v : edge[u])
            if(G[u][v] > 0 && !vis[v]) {
                parent[v] = u;
                vis[v] = 1;
                if(v == t)
                    return 1;
                q.push(v);
            }
    }
    
    return 0;//vis[t];
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
            //pf("%d ", u);
        }
        
        //pf(" :: %d\n", flow);
        Map[nodeChar(parent[t])] = nodeChar(parent[parent[t]]);
        max_flow += flow;
    }
    
    return max_flow;
}

int main() {
    fileRead("in");
    //fileWrite("out");
    
    int source = 0, dest = 37, totFlow = 0;
    string s1;
    cnt = 0;
    
    while(getline(cin, s1)) {

        if(s1.empty()) {                // Newline process
            //pf("DONE________________________\n");
            // Connect right nodes (computers) with sink
            for(char c = '0'; c <= '9'; ++c) {
                int u = toNode(c);
                //cout << "Connect " << u << endl;
                edge[u].pb(dest);
                G[u][dest] = 1;
            }
            
            // Check the answer
            int flow = maxFlow(source, dest);
            //pf("%d --------------- %d\n", flow, totFlow);
            if(flow == totFlow) {
                for(char c = '0'; c <= '9'; ++c) {
                    /*int v = toNode(c);
                    int u = parent[v];
                    
                    if(u != -1)
                        pf("%c(%d)", nodeChar(u), u);
                    else
                        pf("_");*/
                    if(Map.find(c) == Map.end())
                        pf("_");
                    else
                        pf("%c", Map[c]);
                }
                pf("\n");
            }
            else
                pf("!\n");
            
            // Clear All
            toInt.clear();
            toChar.clear();
            cnt = 0;
            totFlow = 0;
            Map.clear();
            memset(G, 0, sizeof G);
            
            
            for(int i = 0; i < 40; ++i)
                edge[i].clear();
            
            continue;
        }
        
        int u = toNode(s1[0]);
        int w = s1[1]-'0';
        
        edge[source].pb(u);
        G[source][u] += w;           // source to node(Applications)
        totFlow += w;               // number of user
        //pf("%c : %d(%d)\n", s1[0], u, w);
        for(int i = 3; i < SIZE(s1)-1; ++i) {     // Application to Computer
            int v = toNode(s1[i]);
            //pf(" %d", v);
            edge[u].pb(v);
            edge[v].pb(u);
            G[u][v] = 1;
        }
        //pf("\n");
    }
    
    return 0;
}
        
