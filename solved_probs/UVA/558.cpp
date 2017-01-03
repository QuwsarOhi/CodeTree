//UVa
//558 - Wormholes
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 50000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

vi g[1010], cost[1010];
int V, E, dist[1010];

void  bellmanFord(int U) {              //complexity O(v^2)
    fr(i, 0, V+1) dist[i] = inf;
    dist[U] = 0;                        //setting start node to zero
    for(int i = 0; i < V -1; i++)       //this loop runs V-1 times
        for(int u = 0; u < V; u++)      //each time for all nodes
            for(size_t j = 0; j < g[u].size(); j++) {
                int v = g[u][j];
                dist[v] = min(dist[v], dist[u] + cost[u][j]);
} }

bool negativeCycle() {
    bool hasNegativeCycle = 0;
    for(int u = 0; u < V; u++)
        for(size_t j = 0; j < g[u].size(); j++) {
            int v = g[u][j];
            if(dist[v] > dist[u] + cost[u][j]) {    //the main case
                hasNegativeCycle = 1;               //to check
                break; }}
    return hasNegativeCycle;
}

int main()
{
    //frein;
    //freout;
    ri t, u, v, c;
    sf("%d", &t);
    wh(t--) {
        sf("%d %d", &V, &E);
        fr(i, 0, E) {
            sf("%d %d %d", &u, &v, &c);
            g[u].pb(v);
            cost[u].pb(c);
        }
        bellmanFord(0);
        if(negativeCycle())pf("possible\n");
        else pf("not possible\n");

        fr(i, 0, V+1) { g[i].clear(); cost[i].clear();}
    }
    return 0;
}
