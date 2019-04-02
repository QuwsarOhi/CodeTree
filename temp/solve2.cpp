#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef long long ll;

struct DS {
    map<ll, ll> s;
    ll totVal;

    void clear() {
        s.clear();
        totVal = 0;
    }
    void insert(ll val) {
        s[val-totVal]++;
    }
    void erase(ll val) {
        ll tmp = val-totVal;
        if(s.count(tmp)) {
            s[tmp]--;
            if(s[tmp] <= 0)
                s.erase(tmp);
        }
    }
    void addEdge(ll val) {
        totVal += val;
    }
    int resize() {
        while((not s.empty()) and ((s.begin())->first)+totVal < 0)
            s.erase(s.begin());
        return s.size();
    }
    int size() {
        return s.size();
    }
} Set;

int sz[MAX];
ll cst[MAX], joy[MAX], ans[MAX];
vector<int>G[MAX];
bitset<MAX>heavy;

int getSZ(int u) {
    sz[u] = 1;
    for(auto v : G[u])
        sz[u] += getSZ(v);
    return sz[u];
}

void add(int u, ll carry) {
    if(joy[u]+carry >= 0)
        Set.insert(joy[u]+carry);
    for(auto v : G[u])
        if(not heavy[v])
            add(v, carry+cst[v]);
}

void remove(int u, ll carry) {
    Set.erase(joy[u]+carry);
    for(auto v : G[u])
        remove(v, carry+cst[v]);
}

void dfs(int u, bool keep) {
    int heavyChild = -1, mx = -1;

    for(auto v : G[u])
        if(sz[v] > mx)
            mx = sz[v], heavyChild = v;

    for(auto v : G[u])
        if(v != heavyChild)
            dfs(v, 0);

    if(heavyChild != -1) {
        dfs(heavyChild, 1);
        heavy[heavyChild] = 1;
        Set.addEdge(cst[heavyChild]);
        Set.resize();
    }
        
    /*cerr << "AT " << u << ", " << heavyChild << " :: (" << Set.totVal << ") ::";
    for(auto it : Set.s)
        cerr << " " << it+Set.totVal;
    cerr << endl;*/

    add(u, 0);
    ans[u] = Set.size();

    /*cerr << "AT " << u << " ::";
    for(auto it : Set.s)
        cerr << " " << it+Set.totVal;
    cerr << endl;*/

    if(heavyChild != -1)
        heavy[heavyChild] = 0;
    if(not keep)
        remove(u, 0);
}

int main() {
    int t, n, p, root;

    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);

        for(int i = 0; i < MAX; ++i)
            G[i].clear();
        Set.clear();
        heavy.reset();
        memset(sz, 0, sizeof sz);

        for(int i = 1; i <= n; ++i)
            scanf("%lld", &joy[i]);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &p);
            if(p == 0) root = i;
            else G[p].push_back(i);
        }
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &cst[i]);

        getSZ(root);
        dfs(root, 0);

        printf("Case %d:\n", Case);
        for(int i = 1; i <= n; ++i)
            printf("%lld\n", ans[i]);
    }
    return 0;
}


/*

6

5
7 3 2 5 1
0 1 1 3 3
0 4 1 0 4

2
3 2
0 1
0 -5

5
7 3 2 5 1
0 1 1 3 3
0 2 -2 -4 -1

3
2 5 1
0 1 1
-2 -4 -1

9
7 3 2 5 1 1 10 5 4
0 1 1 3 3 5 5 2 2
10 2 -2 -4 -1 2 2 0 12


3
2 5 1
0 1 1
-2 -4 -1


Case 1:
3
1
2
1
1
Case 2:
1
1
Case 3:
3
1
3
1
1
Case 4:
3
1
1


*/