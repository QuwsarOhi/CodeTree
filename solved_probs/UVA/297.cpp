// UVa
// 297 - Quadtrees

#include <bits/stdc++.h>
#define MAX 6000
using namespace std;

vector<int>G[MAX];
int C[2][MAX], pos;
string s[2], ans;
// 1 : MIXED(p), 2 : WHITE(e), 3 : BLACK(f)

void FormGraph(int u, int lvl=0) {
    if(lvl == 6)
        return;
    for(int i = 0; i < 4; ++i) {
        G[u].push_back(++pos);
        FormGraph(pos, lvl+1);
    }
}

void BuildTree(int u, int p) {
    if(s[p][pos] != 'p') {
        C[p][u] = (s[p][pos] == 'e' ? 2:3);
        ++pos;
        return;
    }
    
    C[p][u] = 1;
    ++pos;
    for(int i = 0; i < 4; ++i)
        BuildTree(G[u][i], p);
}

void Printer(int u, int mxLvl, int lvl = 0) {
    if(mxLvl == lvl)
        return;
    cout << "FROM " << u << " (" << C[0][u] << ", " << C[1][u] << ")" << endl;
    
    for(auto it : G[u])
        cout << it << " (" << C[0][it] << ", " << C[1][it] << ") ";
    cout << endl;
    for(auto it : G[u])
        Printer(it, mxLvl, lvl+1);
}

int MergeTree(int u, int lvl = 0) {
    if(C[0][u] == 3 or C[1][u] == 3)
        return 1024/pow(4, lvl);
    
    if(C[0][u] == 2 and C[1][u] == 2)
        return 0;
    
    if(C[0][u] == 2 and C[1][u] == -1)
        return 0;
    
    if(C[0][u] == -1 and C[1][u] == 2)
        return 0;
    
    int ret = 0;
    for(auto v : G[u])
        ret += MergeTree(v, lvl+1);
    return ret;
}
    
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    pos = 1;
    FormGraph(1);
    //cout << pos << " DONE\n";
    //Printer(1, 2);
    int t;
    scanf("%d", &t);
    
    while(t--) {
        memset(C, -1, sizeof C);
        cin >> s[0] >> s[1];
        pos = 0;
        BuildTree(1, 0);
        pos = 0;
        BuildTree(1, 1);
        cout << "There are " << MergeTree(1) << " black pixels.\n";
    }
    return 0;
}
