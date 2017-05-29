//UVa
//924 - Spreading The News
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

vi g[2510];
int past_level, level[2510], mx_cnt, day, V, E, cnt;

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    fr(i, 0, V+5) level[i] = N;
    level[u] = 0;
    past_level = 0;
    cnt = mx_cnt = day = 0;
    wh(!q.empty()) {
        u = q.front();
        q.pop();
        for(size_t i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(level[u]+1 > past_level) {
                //pf("in level %d\n", level[u]+1);
                if(cnt > mx_cnt) {
                    day = past_level;
                    mx_cnt = cnt;       //storing the max known people
                    //pf("day %d, mx_cnt %d\n", day, mx_cnt);
                }
                past_level = level[u] + 1;
                cnt = 0;
            }
            if(level[v] == N) {       //level is the no. of day
                level[v] = level[u]+1;
                cnt++;                  //known people
                q.push(v);
            }
        }
    }
    if(level[u]+1 > past_level)         //this checks after the last level is finished
    //pf("in level %d\n", level[u]+1);
        if(cnt > mx_cnt) {
            day = past_level;
            mx_cnt = cnt;       //storing the max known people
            //pf("day %d, mx_cnt %d\n", day, mx_cnt);
        }
}


int main()
{
    //frein;
    //freout;
    ri u, v, q, p;
    sf("%d", &V);
    fr(u, 0, V) {
        sf("%d", &E);
        wh(E--) {
            sf("%d", &v);
            g[u].pb(v);     //all are directed graph
        }
    }
    sf("%d", &q);
    wh(q--) {
        sf("%d", &p);
        bfs(p);
        if(g[p].size() == 0) pf("0\n");
        else pf("%d %d\n", mx_cnt ,day);
    }
    return 0;
}
