#include <bits/stdc++.h>
#define MAX 301000
using namespace std;

typedef long long ll;

vector<ll>G[MAX], C[MAX];
ll w[MAX];
vector<pair<ll, ll> >wp;
bitset<MAX>vis;

map<pair<int, int>, ll>mem;

void dfs(int u, ll fuel, int par = -1) {
    vis[u] = 1;    

    if(fuel < 0) {
        vis[u] = 0; 
        return;
    }

    if(mem.find({u, par}) != mem.end() and mem[{u, par}] > fuel) {
        vis[u] = 0;
        return;
    }


    auto &it = mem[{u, par}];
    it = fuel;

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        int cst = C[u][i];

        if(not vis[v]) {
            dfs(v, fuel+w[v]-cst, u);
            it = max(it, mem[{v, u}]);
        }
    }

    vis[u] = 0;
}

int main() {
    long long V, u, v, c;
    scanf("%lld", &V);

    long long ans = 0;
    for(int i = 1; i <= V; ++i) {
        scanf("%lld", &w[i]);
        ans = max(ans, w[i]);
        wp.push_back({w[i], i});
    }

    for(int i = 1; i < V; ++i) {
        scanf("%lld", &u);
        scanf("%lld", &v);
        scanf("%lld", &c);
        G[u].push_back(v);
        G[v].push_back(u);
        C[u].push_back(c);
        C[v].push_back(c);
    }

    for(auto it : wp) {
        c = it.first;
        u = it.second;

        dfs(u, c);
        ans = max(ans, mem[{u, -1}]);
    }   

    cout << ans << endl;
    return 0;
}