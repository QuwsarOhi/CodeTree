#include <bits/stdc++.h>
#define MAX 100100;
using namespace std;

void dfs(int u, int par = -1, int level = 0) {
    lvl[u] = level;
    for(auto v : G[u])
        if(v != par)
            dfs(v, u, level+1);
}

int Solve(int u, int v) {
    if(lvl[u] < lvl[v]) 
        swap(u, v);

    int w = LCA(u, v);
    int d = lvl[u] + lvl[v] - 2 * lvl[w] - 1; 

    if(d%2 == 0)
        return 0;

    if(w == v)
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);

    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &u, &v);
    }
}