#include <bits/stdc++.h>
#define MOD 998244353
#define MAX 100000
#define dd(XX)       cerr << #XX << " :: " << XX << endl;
using namespace std;
typedef long long ll;

vector<int>G[MAX];
ll c[MAX], sum[MAX];

ll dfs1(int u, int par = -1, int lvl = 1) {
    ll retCst = 0;
    sum[u] = c[u];

    for(auto v : G[u]) {
        if(v == par) continue;
        retCst += dfs1(v, u, lvl+1);
        sum[u] += sum[v];
    }

    cst[u] = retCst;
    return retCst + lvl * c[u];
}

void dfs2(int u, int par = -1, int lvl = 1) {
    ll cst = (rootCst - lvl*c[u] - cst[u])*lvl + cst[u];
    for(auto v : G[u]) {
        if(v == par) continue;
        dfs2(v, u, lvl+1, );
    }
}

int main() {
    cin >> V;

    for(int i = 1; i <= V; ++i)
        cin >> c[i];

    for(int i = 1; i < V; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs1(1);

    return 0;
}