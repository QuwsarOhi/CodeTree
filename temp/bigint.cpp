//UVa
//12376 - As Long as I Learn, I Live
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
#define N 500000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

vi g[100], cost[100];
int dis[100];

void dikjstra(int u)
{
    fr(i, 0, arrsize(dis)) dis[i] = inf;    //dis[node] = distance
    priority_queue<pii>pq;                  //priority queue to sort the nodes according their cost
    dis[u] = 0;                             //setting starting distance to zero
    pq.push(mp(u, dis[u]));                 //node, distance
    while(!pq.empty()) {
        u = pq.top().first;                 //taking the smallest node of shortest distance
        pq.pop();
        for(size_t i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(dis[u] + cost[u][i] < dis[v]) {
                pf("dis[%d](%d) + cost[%d][%d](%d) < dis[%d](%d)\n", u, dis[u], u, i, cost[u][i], v, dis[v]);
                dis[v] = cost[u][i] + dis[u];
                pq.push(mp(v, dis[v]));
            }
        }
    }
}

int main()
{
    ri V, E, u, v, c;
    wh(sf("%d %d", &V, &E) && (V || E)) {
        wh(E--) {
            sf("%d %d %d", &u, &v, &c);
            g[u].pb(v);
            g[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }
        pf("value got\n");
        dikjstra(1);
        fr(i, 1, V+1) {
            for(size_t j = 0; j < g[i].size(); j++)
                pf("%d - %d = %d\n", i, g[i][j], dis[g[i][j]]);
        }
        fr(i, 0, 100) { g[i].clear(), cost[i].clear();}
    }
    return 0;
}
