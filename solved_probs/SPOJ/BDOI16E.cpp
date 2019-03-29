// SOPJ
// BDOI16E

#include <bits/stdc++.h>
#define MAX 100100
using namespace std;


vector<int>G[MAX];
map<long long, long long>joy;
long long ans[MAX], val[MAX], d[MAX], heavyChild[MAX];


int dfs(int u, int p, int carry) {
    int sz = 0, ret = 1;
    heavyChild[u] = -1;
    carry += d[u];
    val[u] += carry;

    for(int v : G[u]) {
        if(v == p) continue;
        
        int t = dfs(v, u, carry);
        ret += t;
        
        if(heavyChild[u] == -1 or sz < t)
            heavyChild[u] = v, sz = t;
    }

    return ret;
}

void add(int u, int p, int heavy, int x) {
    joy[val[u]] += x;
    if(joy[val[u]] == 0)
        joy.erase(val[u]);

    for(auto v : G[u])
        if(v != p and v != heavy)
            add(v, u, -1, x);
}

void DSUonTree(int u, int p, bool keep) {
    for(auto v : G[u])
        if(v != p and v != heavyChild[u])
            DSUonTree(v, u, 0);

    if(heavyChild[u] != -1)
        DSUonTree(heavyChild[u], u, 1);

    add(u, p, heavyChild[u], 1);

    ans[u] = joy.size();

    if(not keep)
        add(u, p, -1, -1);
}


int main() {
    int n, x, root;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        if(x == 0)
            root = i;
        else
            G[i].push_back(x), G[x].push_back(i);
    }

    for(int i = 1; i <= n; ++i)
        scanf("%lld", &d[i]);

    dfs(root, -1, 0);
    DSUonTree(root, -1, 1);

    for(int i = 1; i <= n; ++i)
        printf("%lld\n", ans[i]);

    return 0;
}

/*

5

7 3 2 5 1

0 1 1 3 3

0 4 1 1 4

*/