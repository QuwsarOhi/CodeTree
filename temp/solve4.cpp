// UVa
// 11374 - Airport Express
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=2369&mosmsg=Submission+received+with+ID+21798418

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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

vi G[2][MAX], W[2][MAX];
int dist[MAX][2], changeState;
pii parent[MAX][2];

void pathPrint(int s, int state, int t) {
    if(s==t) {
        pf("%d", s);
        return;
    }
    pii p = parent[s][state];
    
    //cerr << s << ", " << state << " -> " << p.fi << ", " << p.se << endl;
    //getchar();
    
    if(p.se != state)
        changeState = p.fi;
    pathPrint(p.fi, p.se, t);
    pf(" %d", s);
}

void dikjstra(int s, int t) {
    queue<pii>q;
    q.push({s, 0});
    
    //cerr << "init Start\n";
    //getchar();
    
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < 2; ++j)
            dist[i][j] = INF;
    dist[s][0] = 0;
    
    //cerr << "DONE INIT\n";
    getchar();
    
    while(not q.empty()) {
        int u = q.front().fi, state = q.front().se;
        q.pop();
        
        //cerr << "AT " << u << " " << state << endl;
        
        for(int i = 0; i < 2; ++i) {
            if(state == 1 and i == 1) continue;
            
            for(int j = 0; j < (int)G[i][u].size(); ++j) {
                int w = W[i][u][j] + dist[u][state], v = G[i][u][j];
                
               // cerr << "From " << u << " to " << v << " " << w << " " << i;
                
                if(dist[v][state or (i==1)] > w) {
                    //cerr << " added\n";
                    parent[v][state or (i==1)] = {u, state};
                    dist[v][state or (i==1)] = w;
                    q.push({v, state or (i==1)});
                }
                //else
                    //cerr << " skipped\n";
            }
        }
    }
    //cerr << "Dikjstra done\n";
}

int main() {
    //fileRead("in");
    //fileWrite("out");
    
    int V, E, s, t, u, v, w;
    bool first = 1;
    
    while(sf("%d%d%d", &V, &s, &t) == 3) {
        if(not first) pf("\n");
        first = 0;
        
        for(int i = 0; i < 2; ++i) {
            sf("%d", &E);
            while(E--) {
                sf("%d%d%d", &u, &v, &w);
                G[i][u].pb(v), G[i][v].pb(u);
                W[i][u].pb(w), W[i][v].pb(w);
            }
        }
        //cerr << "DONE\n";
        dikjstra(s, t);
       // cerr << "DONE\n";
        //getchar();
        int state = dist[t][1] < dist[t][0];
        
        //cerr << "MINDIST " << dist[t][state] << endl;
        
        pathPrint(t, state, s);
        pf("\n");
        if(state == 0)
            puts("Ticket Not Used");
        else
            pf("%d\n", changeState);
        pf("%d\n", dist[t][state]);
        
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j <= V; ++j) G[i][j].clear(), W[i][j].clear();
    }
    return 0;
}
