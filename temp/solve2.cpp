#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int u, int p) {
    tot[u] = tot[p] + 


int main() {
    int t;
    scanf("%d", &t);

    for(int i = 1; i <= Case; ++i) {
        scanf("%d%d", &n, &x);
        
        for(int i = 1; i <= n; ++i)
            scanf("%d", &c[i]);

        for(int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }




