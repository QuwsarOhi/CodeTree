// LightOJ
// 1003 - Drunk

#include <bits/stdc++.h>
using namespace std;

int Ncnt, InDegree[20010];
map<string, int>mp;
vector<int>G[20010];
bitset<20010>visited;

int NodeNo(string x) {
    if(mp.find(x) != mp.end())
        return mp[x];
    mp[x] = ++Ncnt;
    return Ncnt;
}

bool TopSort() {
    memset(InDegree, 0, sizeof InDegree);
    for(int u = 1; u <= Ncnt; ++u) {
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            ++InDegree[v];
        }
    }

    queue<int>q;
    for(int i = 1; i <= Ncnt; ++i)
        if(InDegree[i] == 0)
            q.push(i);

    visited.reset();
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = 1;
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            --InDegree[v];
            if(InDegree[v] == 0)
                q.push(v);
        }
    }
    if((int)visited.count() == Ncnt)
        return 1;
    return 0;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, u, v, n;
    string a, b;
    cin >> t;

    for(int Case = 1; Case <= t; ++Case) {
        cin >> n;
        mp.clear();
        Ncnt = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a >> b;
            u = NodeNo(a);
            v = NodeNo(b);
            G[u].push_back(v);
        }

        cout << "Case " << Case << ": ";
        if(TopSort() == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
        for(int i = 0; i <= Ncnt; ++i)
            G[i].clear();
    }
    return 0;
}
