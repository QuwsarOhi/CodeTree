// UVa
// 531 - Compromise

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

map<string, int>Map;
vector<string>Remap;

int cnt = 0, p = 0, v[2][120], dp[120][120], l[2];

int Mapper(string str) {
    if(Map.find(str) == Map.end()) {
        Remap.push_back(str); 
        return Map[str] = cnt++;
    }
    return Map[str];
}

int grabber() {
    string str;
    int i = 0;
    while(cin >> str) {
        if(str == "#") {
            l[p] = i;
            return 1;
        }
        v[p][i++] = Mapper(str);
    }
    return 0;
}

int recur(int p1, int p2) {
    if(p1 == l[0] or p2 == l[1])
        return dp[p1][p2] = 0;
    
    if(dp[p1][p2] != -1)
        return dp[p1][p2];
    
    if(v[0][p1] == v[1][p2])
        return dp[p1][p2] = recur(p1+1, p2+1)+1;
    
    return dp[p1][p2] = max(recur(p1+1, p2), recur(p1, p2+1));
}

void dfs(int p1, int p2, bool first) {
    if(dp[p1][p2] <= 0)
        return;
    
    if(v[0][p1] == v[1][p2]) {
        if(!first) cout << " ";
        first = 0;
        cout << Remap[v[0][p1]];
        dfs(p1+1, p2+1, 0);
        return;
    }
    
    int P = max(mp(dp[p1+1][p2+1], 1), max(mp(dp[p1+1][p2], 2), mp(dp[p1][p2+1], 3))).second;
    if(P == 1)
        dfs(p1+1, p2+1, first);
    else if(P == 2)
        dfs(p1+1, p2, first);
    else
        dfs(p1, p2+1, first);
}


int main() {
    while(grabber()) {
        ++p;
        if(!grabber())
            break;
        
        memset(dp, -1, sizeof dp);
        recur(0, 0);
        dfs(0, 0, 1);

        cnt = p = l[0] = l[1] = 0;
        Map.clear();
        Remap.clear();
        cout << "\n";
    }
    
    return 0;
}
