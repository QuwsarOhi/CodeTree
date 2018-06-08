// LightOJ
// 1075 - Finding Routes

#include <bits/stdc++.h>
using namespace std;

map<string, int>Map;
vector<string>ReMap;
int MapCnt;
vector<int>G[670];

char s1[100000], s2[100000];
int indegree[670];

int conv(char s[]) {
    string str(s);
    if(Map.find(s) == Map.end()) {
        Map[str] = MapCnt++;
        ReMap.push_back(str);
        return MapCnt-1;
    }
    return Map[s];
}

void dfs(int u) {
    printf("%s\n", ReMap[u].c_str());
    for(int i = 0; i < (int)G[u].size(); ++i)
        dfs(G[u][i]);
    indegree[u] = 0;
    G[u].clear();
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, u, v, n;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        
        for(int i = 1; i < n; ++i) {
            scanf("%s %s", s1, s2);
            u = conv(s1), v = conv(s2);
            G[u].push_back(v);
            indegree[v]++;
        }
        
        printf("Case %d:\n", Case);
        for(int i = 0; i < MapCnt; ++i)
            if(indegree[i] == 0) {
                dfs(i);
                break;
            }
        printf("\n");
        Map.clear();
        ReMap.clear();
        MapCnt = 0;
    }
    return 0;
}
