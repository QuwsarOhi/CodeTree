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
#define ii pair<int, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 500000
#define ri register int
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

vi g[110];
bitset<110>visited;
int cost[110];

int max_node(int u)
{
    int pos = -1, mx = -1;
    visited[u] = 1;
    for(size_t i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!visited[v]) {
            if(cost[v] > mx) {
                mx = cost[v];
                pos = v;
            }
        }
    }
    return pos;
}

int main()
{
    //frein;
    //freout;
    ri t, total, u, v, V, E;
    sf("%d", &t);
    fr(c, 1, t+1) {
        sf("%d %d", &V, &E);
        fr(i, 0, V) {
            sf("%d", &cost[i]);
            //pf("%d\n", cost[i]);
        }
        fr(i, 0, E) {
            sf(" %d %d", &u, &v);
            g[u].pb(v);
        }
        visited.reset();
        u = total = 0;
        do{
            //pf("max cost of %d is %d\n", u, cost[u]);
            total += cost[u];
            //pf("total is %d\n", total);
            u = max_node(u);
        }while(g[u].size() != 0);
        total+=cost[u];
        pf("Case %d: %d %d\n", c, total, u);
        fr(i, 0, V) g[i].clear();
    }
    return 0;
}
