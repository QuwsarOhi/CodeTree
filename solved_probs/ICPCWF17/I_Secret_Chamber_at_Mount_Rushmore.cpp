#include <bits/stdc++.h>
using namespace std;

vector<int>G[30];
bool visited[30];

bool canGo(int u, int v) {
    visited[u] = 1;
    if(u == v)
        return 1;
    for(auto it : G[u]) {
        if(!visited[it]) {
            bool ans = canGo(it, v);
            if(ans)
                return ans;
        }
    }
    return 0;
}


int main() {
    int n, m;
    char u, v;
    string s1, s2;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> u >> v;
        G[u-'a'].push_back(v-'a');
    }
    for(int i = 0; i < m; ++i) {
        cin >> s1 >> s2;
        bool ok = 1;
        if(s1.size() == s2.size()) {
            for(int i = 0; i < s1.size(); ++i) {
                memset(visited, 0, sizeof visited);
                if(!canGo(s1[i]-'a', s2[i]-'a')) {
                    ok = 0;
                }
            }
        }

        if((s1.size() != s2.size()) || (ok != 1))
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}
