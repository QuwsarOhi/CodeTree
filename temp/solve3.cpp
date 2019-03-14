#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef long long ll;

vector<int>G[MAX];
int sz[MAX], heavy[MAX];
ll val[MAX];

int init(int u, int p) {
    int heavyChild = -1;
    sz[u] = 1;
    for(int v : G[u])
        if(v != p) {
            sz[u] += init(v, u);
            if(heavyChild == -1 or sz[heavyChild] < sz[v])
                heavyChild = v;
        }
    heavy[u] = heavyChild;
    return sz[u];
}

ll ans;
map<ll, ll> *child[MAX];

void dfs(int u, int p) {
    cerr << "AT " << u << " " << p << endl;
    int heavyChild = heavy[u];

    for(int v : G[u])
        if(v != p and v != heavyChild)
            dfs(v, u);

    if(heavyChild != -1) {
        dfs(heavyChild, u);
        child[val[u]] = child[val[heavyChild]];
    }
    else
        child[u] = new map<ll, ll>();

    cerr << "NOW " << u << endl;
    ll rootval = val[u];

    for(int v : G[u])
        if(v != p and v != heavyChild) {
            cerr << "COUNTING " << v << endl;
            for(auto w : *child[v]) {
                cerr << w.first << ", " << w.second << endl;
                if(rootval%w.first == 0) {
                    cerr << "ADDCOUNT\n";
                    auto it = (*child[u]).find(rootval/w.first);
                    cerr << "FOUND\n";
                    if(it != (*child[u]).end()) {
                        cerr << "ADDFOUND\n";
                        ans += it->second*w.second;
                    }
                }
            }
            cerr << "MERGE " << v << endl;
            for(auto w : *child[v])
                (*child[u])[w.first] += w.second;
        }

    cerr << u << " DONE ";
    (*child[u])[rootval]++;
    cerr << "ADDED\n";
}

int main() {
    int n, u, v;
    cin >> n;

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i)
        cin >> val[i];

    init(1, 0);
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}