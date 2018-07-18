#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long>pll;

// Bipartite DSU (Checked, Not Tested)

// Bipartite DSU

struct BipartiteDSU {
    vector<int>u_list, u_set, u_color;
    vector<bool>missmatch;                                  // Bicolor missmatch
    
    BipartiteDSU() {}
    BipartiteDSU(int SZ) { init(SZ); }
    
    pll unionRoot(int n) {                                  // Union making with dynamic compression
        if(u_set[n] == n) return {n, u_color[n]};
        pll root = unionRoot(u_set[n]);
        if(missmatch[u_set[n]] or missmatch[n])
            missmatch[n] = missmatch[u_set[n]] = 1;
        u_color[n] = (u_color[n] + root.second)&1;
        u_set[n] = root.first;                              // Directly set the actual root of this set as root (Compress)
        return {u_set[n], u_color[n]};
    }

    int makeUnion(int a, int b) {                                   // Union making with compression
        int x = unionRoot(a).first, y = unionRoot(b).first;
        if(x == y) {                                                // If both are in same set and bipartite missmatch exists
            if(u_color[x] == u_color[y])
                missmatch[x] = 1;
            return x;
        }
        
        if(missmatch[x] or missmatch[y])                            // Checks if Bipartite missmatch exists
            missmatch[x] = missmatch[y] = 1;
            
        if(u_list[x] > u_list[y]) {                                 // Makes x root (y -> x)
            u_set[y] = x;
            u_list[y] += u_list[x];                                 // Root's size is increased
            u_color[y] = (u_color[a] + u_color[b] + 1)&1;           // Setting color of component y according to the color of a & b
            return x;
        }
        else {                                                      // Makes y root (x -> y)
            u_set[x] = y;
            u_list[x] += u_list[y];                                 // Root's size is increased
            u_color[x] = (u_color[a] + u_color[b] + 1)&1;           // Setting color of component y according to the color of a & b
            return y;
    }}

    void init(int len) {                                    // Initializer
        u_list.resize(len+5);
        u_set.resize(len+5);
        u_color.resize(len+5);
        missmatch.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1, u_color[i] = 0, missmatch[i] = 0;
    }
    
    bool isRoot(int x) {                                    // Returns true if this is a root (May contain one or many nodes)
        return u_set[x] == x;
    }
    
    bool isRootContainsMany(int x) {                        // If the root contains more than one value (Actual Root)
        return (isRoot(x) && (u_list[x] > 1));
    }
    
    bool isSameSet(int a, int b) {                          // If a and b is in same set/component
        return (unionRoot(a).first == unionRoot(b).first);
    }
    
    bool getColor(int u) {                                  // Color of node u (DONT get the color of root)
        return u_color[u];
    }
    
    bool hasMissmatch(int x) {                              // If there is bipartite missmatch in this set/component
        return missmatch[x];
}};

BipartiteDSU dsu;
ll v[100010];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    ll n, q, x, y, c, t;
    scanf("%lld%lld", &n, &q);
    
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &v[i]);
    
    dsu.init(n);
    while(q--) {
        scanf("%lld", &t);
        scanf("%lld%lld", &x, &y);
        if(t == 1)
            v[x] = y;
        else if(t == 2)
            dsu.makeUnion(x, y);
        else {
            scanf("%lld", &c);
            if((not dsu.isSameSet(x, y)) or dsu.hasMissmatch(dsu.unionRoot(x).first)  or dsu.hasMissmatch(dsu.unionRoot(y).first) or dsu.hasMissmatch(x) or dsu.hasMissmatch(y)) {
                printf("0\n");
                continue;
            }
            
            ll a = v[x]*c, b = v[y];
            ll TT = __gcd(a, b);
            a /= TT, b /= TT;
            
            if(dsu.getColor(x) != dsu.getColor(y))
                a = -a;
            printf("%lld/%lld\n", a, b);
        }
        
        /*for(int i = 1; i <= 4; ++i)
            cout << dsu.u_set[i] << " ";
        cout << endl;
        for(int i = 1; i <= 4; ++i)
            cout << dsu.u_color[i] << " ";
        cout << endl;*/
    }
    return 0;
}


// 2, 3, 5
