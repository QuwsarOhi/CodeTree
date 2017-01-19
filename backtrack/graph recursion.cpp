//UVa
//775 - Hamiltonian Cycle
#include<bits/stdc++.h>
using namespace std;

vector<int>g[260];
bitset<260>visited;
int n, start, u1, v1, v[260], cnt;
char a[150];
bool found;
set<pair<int, int> >s;

void hamilton_cycle(int u)
{
    if(found) return;
    if(cnt == n) {
        if(s.find(make_pair(u, start)) == s.end()) return;      //using memorized function(instead of linear search) to save time
        found = 1;
        for(size_t i = 0; i < cnt; i++)
            printf("%d ", v[i]);
        printf("%d\n", start);
        return;
    }
    for(size_t i = 0; i < g[u].size(); i++) {
        int V = g[u][i];
        if(!visited[V] && V != start && V != u) {       //avoiding start position, cycles and visited vertex
            visited[V] = 1;
            v[cnt++] = V;
            hamilton_cycle(V);
            if(found) return;
            visited[V] = 0;
            --cnt;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        while(1) {
            scanf(" %[^\n]", a);
            if(a[0] == '%') break;
            stringstream ss;
            ss << string(a);
            ss >> u1;
            ss >> v1;
            g[u1].push_back(v1);
            g[v1].push_back(u1);
            if(u1 == 1 || v1 == 1)
                s.insert(make_pair(max(u1, v1), min(u1, v1)));
        }
        found = 0;
        start = 1;
        visited.reset();
        v[0] = cnt = 1;
        hamilton_cycle(1);
        if(!found) printf("N\n");
        for(int i = 0; i <= n; i++) g[i].clear();
        s.clear();
    }
    return 0;
}
