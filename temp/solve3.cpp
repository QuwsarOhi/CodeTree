#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long>pll;


struct BipartiteDSU {
    vector<int>u_list, u_set, u_color;
    vector<bool>blocked;                    // added for problem
    
    BipartiteDSU() {}
    BipartiteDSU(int SZ) { init(SZ); }
    
    pll unionRoot(int n) {
        if(u_set[n] == n) return {n, u_color[n]};
        pll root = unionRoot(u_set[n]);
        u_set[n] = root.first;
        u_color[n] = (u_color[n] + root.second)&1;
        return {u_set[n], u_color[n]};
    }

    int makeUnion(int a, int b) {
        int x = unionRoot(a).first, y = unionRoot(b).first;     // u_set[x] = y, root of x is y, x->y
        if(x == y) {
            if(u_color[x] == u_color[y])                        // same color
                blocked[x] = blocked[y] = 1;
            return x;
        }
        
        if(blocked[x] or blocked[y])
            blocked[x] = blocked[y] = 1;
            
        if(u_list[x] > u_list[y]) {            
            u_set[y] = x;
            u_list[x] += u_list[y];
            u_color[y] = (u_color[a] + u_color[b] + 1)&1;
            return x;
        }
        else {
            u_set[x] = y;
            u_list[y] += u_list[x];
            u_color[x] = (u_color[a] + u_color[b] + 1)&1;
            return y;
    }}

    void init(int len) {
        u_list.resize(len+5);
        u_set.resize(len+5);
        u_color.resize(len+5);
        blocked.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_color[i] = 0;
    }
    
    bool isRoot(int x) {
        return u_set[x] == x;
    }
    
    bool isRootContainsMany(int x) {
        return (isRoot(x) && (u_list[x] > 1));
    }
    
    bool isSameSet(int a, int b) {
        return (unionRoot(a) == unionRoot(b));
    }
};


// Also create a weighted DSU 

int main() {
    BipartiteDSU dsu(10);
    while(1) {
        int u, v, t;
        cin >> t;
        if(t == 1) {
            cin >> u >> v;
            dsu.makeUnion(u, v);
        
            for(int i = 1; i < 5; ++i)
                cout << dsu.u_set[i] << " ";
            cout << endl;
            for(int i = 1; i < 5; ++i)
                cout << dsu.u_list[i] << " ";
            cout << endl;
            for(int i = 1; i < 5; ++i)
                cout << dsu.u_color[i] << " ";
            cout << endl;
        }
        else {
            cin >> u;
            pll xx = dsu.unionRoot(u);
            cout << xx.first << " " << xx.second << endl;
        }
    }
    return 0;
}
