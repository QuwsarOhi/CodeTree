// UVA
// 10080 - Gopher II
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1021

#include <bits/stdc++.h>
using namespace std;
#define MAX                 225
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

vi G[MAX];
vector<pair<double, double> > p1, p2;
int lft[MAX], rht[MAX];
bitset<MAX>vis;

int vertexCover(int u) {
    vis[u] = 1;
    for(int v : G[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        if(lft[v] == -1) {
            lft[v] = u, rht[u] = v;
            return 1;
        }
        else if(vertexCover(lft[v])) {
            lft[v] = u, rht[u] = v;
            return 1;
    }}
    return 0;
}

int BPM(int n) {                            // Bipartite Matching
    int cnt = 0;
    memset(lft, -1, sizeof lft);
    memset(rht, -1, sizeof rht);
    for(int i = 0; i < n; ++i) {           // Nodes are numbered from 1 to n
        vis.reset();
        cnt += vertexCover(i);              // Check if there exists a match for node i
    }
    return cnt;
}

double dist(double x1, double y1, double x2, double y2) {
    double x = x1-x2, y = y1-y2;
    return sqrt(x*x + y*y);
}

void addEdge(int u, int v) {
    G[u].pb(v);
    G[v].pb(u);
}

int source = 0, dest = 220, offset = 110;

int main() {
    int n, m, s, v;
    while(sf("%d%d%d%d", &n, &m, &s, &v) == 4) {
        for(int i = 0; i < MAX; ++i) G[i].clear();
        
        p1.resize(n);
        for(int i = 0; i < n; ++i) {
            sf("%lf%lf", &p1[i].fi, &p1[i].se);
            //addEdge(0, i);
        }
        
        p2.resize(m);
        for(int i = 0; i < m; ++i) {
            sf("%lf%lf", &p2[i].fi, &p2[i].se);
            //addEdge(offset+i, dest);
        }
        //sort(All(p1)), sort(All(p2));
    
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                double t = dist(p1[i].fi, p1[i].se, p2[j].fi, p2[j].se)/v;
                if(t > s) {
                    //cerr << "reject " << t << endl;
                    continue;
                }
                addEdge(i, offset+j);
                //cerr << "ADDED " << i+1 << " " << j << " time " << t << endl;
            }
    
        pf("%d\n", n-BPM(n));
    }
    return 0;
}
    

/*

2 2 14 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0

2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0

*/
