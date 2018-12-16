#include <bits/stdc++.h>
#define MAX 300100
using namespace std;

typedef long long ll;

vector<pair<ll, ll> > G[MAX];
ll w[MAX];

ll ans = 0;

ll dfs(int u, int par = -1) {
    vector<ll>seg;

    for(auto v : G[u]) {
        if(v.first == par) continue;
        seg.push_back(dfs(v.first, u) - v.second);
    }

    if(seg.size() == 0) {
        ans = max(ans, w[u]);
        return w[u];
    }

    sort(seg.begin(), seg.end(), greater<ll>());
    ll ret = max(seg[0], 0LL) + w[u];

    ans = max(ans, ret);
    //ans = max(ans, w[u]);
    if(seg.size() > 1)
        ans = max(ans, ret + seg[1]);

    return ret;
}

int main() {
    ll V, u, v, c;
    cin >> V;

    for(int i = 1; i <= V; ++i)
        cin >> w[i];

    for(int i = 1; i < V; ++i) {
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    dfs(1);
    cout << ans << endl;
    return 0;
}