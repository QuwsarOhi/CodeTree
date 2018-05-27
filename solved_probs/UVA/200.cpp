// UVa
// 200 - Rare Order
// DAG, Longest Sequence

#include <bits/stdc++.h>
using namespace std;

vector<int>G[30];
vector<string>V;
set<pair<char, char> >Set;

vector<char>T, Ans;

void recur(int u) {
    if(G[u].empty()) {
        if(T.size() > Ans.size()) {
            Ans.clear();
            Ans = T;
        }
        return;
    }
    
    for(auto v : G[u]) {
        T.push_back(v+'A');
        recur(v);
        T.pop_back();
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    string str;
    
    while(cin >> str) {
        if(str[0] != '#') {
            V.push_back(str);
            continue;
        }
        
        for(int i = 0; i < (int)V.size(); ++i) {
            for(int j = i+1; j < (int)V.size(); ++j) {
                int l = min(V[i].size(), V[j].size());
            
                for(int k = 0; k < l; ++k)
                    if(V[i][k] != V[j][k]) {
                        if(Set.count({V[i][k], V[j][k]}))
                            goto pass;
                        Set.insert({V[i][k], V[j][k]});
                        G[V[i][k]-'A'].push_back(V[j][k]-'A');
                        goto pass;
                    }
            }
            pass:;
        }

    
        for(int i = 0; i < 26; ++i) {
            if(not G[i].empty()) {
                T.push_back(i+'A');
                recur(i);
                T.pop_back();
            }
        }
    
        for(auto it : Ans)
            cout << it;
        cout << endl;
        
        V.clear();
        T.clear();
        Ans.clear();
        Set.clear();
        for(int i = 0; i < 26; ++i)
            G[i].clear();
    }
    return 0;
}
