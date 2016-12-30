//UVa
//11396 - Claw Decomposition
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI acos(-1)
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
#define EPS 1e-3
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

vi g[310];
bool isBipartite;
int color[310];

void bipartite(int U)
{
    memset(color, -1, sizeof(color));
    color[U] = 1;
    queue <int>q;
    q.push(U);
    isBipartite = 1;
    wh(!q.empty()) {
        int u = q.front();
        q.pop();
        for(size_t i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[u] == color[v]) {
                isBipartite = 0;
                break;
}}}}

int main()
{
    //frein;
    //freout;
    register int t, v1, v2;
    wh(sf("%d", &t) && t) {
        wh(sf("%d %d", &v1, &v2) && v1 && v2) {
            g[v1].pb(v2);
            g[v2].pb(v1);
        }
        bipartite(1);
        if(isBipartite) pf("YES\n");
        else pf("NO\n");
        fr(i, 0, t+1) g[i].clear();
    }
    return 0;
}
