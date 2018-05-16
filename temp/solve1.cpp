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

void grabber() {
    string str;
    int i = 0;
    while(1) {
        getline(cin, str);
        stringstream ss;
        ss << str;
        
        while(ss >> str) {
            if(str[0] == '#') {
                l[p] = i;
                cout << endl;
                return;
            }
            v[p][i++] = Mapper(str);
            cout << v[p][i-1] << " ";
        }
    }
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

bool first = 1;
void dfs(int p1, int p2) {
    cout << "\nAT " << p1 << " " << p2 << " " << dp[p1][p2] << endl;
    if(dp[p1][p2] <= 0)
        return;
    
    if(!first) cout << " ";
    if(v[0][p1] == v[1][p2]) {
        first = 0;
        cout << Remap[v[0][p1]];
        dfs(p1+1, p2+1);
        return;
    }
    
    int P = max(mp(dp[p1+1][p2+1], 1), min(mp(dp[p1+1][p2], 2), mp(dp[p1][p2+1], 3))).second;
    if(P == 1)
        dfs(p1+1, p2+1);
    else if(P == 2)
        dfs(p1+1, p2);
    else
        dfs(p1, p2+1);
}


int main() {
    grabber();
    ++p;
    grabber();
    
    memset(dp, -1, sizeof dp);
    cout << l[0] << " " << l[1] << endl;
    cout << recur(0, 0) << endl;
    dfs(0, 0);
    return 0;
}
