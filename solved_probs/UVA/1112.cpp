//UVa
//1112 - Mice and Maze
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

vi g[110], cost[110];
int dis[110], T, V, X, E;
set<int>node_set;

int dikjstra(int u)
{
    //pf("working in %d\n", u);
    fr(i, 0, V+10) dis[i] = inf;
    priority_queue<pii>pq;
    dis[u] = 0;
    pq.push(mp(u, dis[u]));
    wh(!pq.empty()) {
        u = pq.top().first;
        pq.pop();
        for(size_t i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(dis[u] + cost[u][i] < dis[v]) {
                dis[v] = cost[u][i] + dis[u];
                //pf("node %d updated to %d\n", v, dis[v]);
                if(v == X && dis[v] <= T) {
                    //pf("node %d is valid\n", );
                    return 1;
                }
                pq.push(mp(v, dis[v]));
            }
        }
    }
    return 0;
}

int main()
{
    //frein;
    //freout;
    ri u, v, c, t, total;
    sf("%d", &t);
    wh(t--) {
        sf(" %d %d %d %d", &V, &X, &T, &E);
        fr(i, 0, E) {
            sf(" %d %d %d", &u, &v, &c);
            g[u].pb(v);
            cost[u].pb(c);
        }
        total = 0;
        //pf("V: %d X: %d T: %d E: %d\n", V, X, T, E);
        //pf("exit node %d\n", X);
        fr(i, 1, V+2) {
            if(i != X) total+=dikjstra(i);
        }
        pf("%d\n", (int)total+1);
        fr(i, 0, V+3) {g[i].clear(); cost[i].clear();}
        //node_set.clear();
        if(t) pf("\n");
    }
}
