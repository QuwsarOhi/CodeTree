// Toph
// https://toph.co/p/secret-sorting-order
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
        T.push_back(v+'a');
        recur(v);
        T.pop_back();
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    string str;
    
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        while(n--) {
            cin >> str;
            V.push_back(str);
        }
        
        //cout << "INPUT DONE\n";
        
        for(int i = 0; i < (int)V.size(); ++i) {
            for(int j = i+1; j < (int)V.size(); ++j) {
                int l = min(V[i].size(), V[j].size());
            
                for(int k = 0; k < l; ++k)
                    if(V[i][k] != V[j][k]) {
                        if(Set.count({V[i][k], V[j][k]}))
                            goto pass;
                        Set.insert({V[i][k], V[j][k]});
                        //cout << "GOT" << endl;
                        G[V[i][k]-'a'].push_back(V[j][k]-'a');
                        goto pass;
                    }
            }
            pass:;
        }

    
        for(int i = 0; i < 26; ++i) {
            if(not G[i].empty()) {
                T.push_back(i+'a');
                recur(i);
                T.pop_back();
            }
        }
    
        bool first = 1;
        for(auto it : Ans) {
            if(not first)
                cout << " ";
            first = 0;
            cout << it;
        }
        
        if(Ans.empty())
            cout << V[0][0];
        
        cout << "\n";
        
        V.clear();
        T.clear();
        Ans.clear();
        Set.clear();
        for(int i = 0; i < 26; ++i)
            G[i].clear();
    }
    return 0;
}


/*
Input:
5
3
aaa
aaa
aaa
4
ab
ca
cb
cc
5
xwy
zx
zxy
zxw
ywwx
20
qdddklkk
qdddklkn
qlkln
qlkkdl
qlknddq
qlknnnqndk
qlnkl
qklkqnkq
qklkfflql
dnkln
dnkndlq
dnkndkdkqf
dnknfnn
dnnffq
dnnfffl
dnnffk
dnnflqq
dnnfll
dnnflln
dnnflkdf
4
b
a
c
d
*/

/*
Output:
a
a b c
x z y w
q d f l k n
b a c d
*/
