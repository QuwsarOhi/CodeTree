// Codeforces
// http://codeforces.com/contest/620/problem/E
// Segment Tree + DFS

#include <bits/stdc++.h>
#define MAX 440000
using namespace std;
typedef long long ll;

vector<int>G[MAX];
vector<pair<int, int> >range;
bitset<MAX>vis;

struct node {
    ll val;
    bool prop;
};

node tree[5*MAX];
ll color[MAX];
int timeToNode[MAX], timer = 1;

void dfs(int u) {
    vis[u] = 1;
    timeToNode[timer] = u;    
    range[u].first = timer;
    
    for(auto v : G[u])
        if(!vis[v]) {
            ++timer;
            dfs(v);
        }
    
    range[u].second = timer;
}

// DO bitwise!!! 

void bitp(ll val) {
    bitset<60>b(val);
    cout << b << endl;
}

void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos].val = (1LL<<color[timeToNode[l]]);
        return;
    }
    
    int mid = (l+r)>>1;
    
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    tree[pos].val = tree[pos<<1].val | tree[pos<<1|1].val;
}

void propagate(int pos, int l, int r) {
    if(l == r || tree[pos].prop == 0)
        return;
    
    tree[pos<<1].val = tree[pos<<1|1].val = tree[pos].val;
    tree[pos<<1].prop = tree[pos<<1|1].prop = 1;
    tree[pos].prop = 0;
}

void update(int pos, int l, int r, int L, int R, ll newColor) {
    if(r < L || R < l)
        return;
    
    propagate(pos, l, r);
    if(L <= l && r <= R) {
        tree[pos].val = (1LL<<newColor);
        tree[pos].prop = 1;        
        return;
    }
    
    int mid = (l+r)>>1;
    update(pos<<1, l, mid, L, R, newColor);
    update(pos<<1|1, mid+1, r, L, R, newColor);
    tree[pos].val = tree[pos<<1].val | tree[pos<<1|1].val;
}

ll query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return 0LL;
    
    propagate(pos, l, r);
    if(L <= l && r <= R)
        return tree[pos].val;
    
    int mid = (l+r)>>1;
    return (query(pos<<1, l, mid, L, R) | query(pos<<1|1, mid+1, r, L, R));
}

void ConvertUpdate(int u, int newColor, int V) {
    int L = range[u].first;
    int R = range[u].second;

    update(1, 1, V, L, R, newColor);
}

int ConvertQuery(int u, int V) {
    int L = range[u].first;
    int R = range[u].second;
    
    ll ret = query(1, 1, V, L, R);
    int cnt = 0;
    
    //bitp(ret);
    for(ll i = 62; i > 0; --i)
        if(ret & (1LL<<i))
            ++cnt;
    
    return cnt;
}

int main() {
    int V, Q, u, v, t, newColor;
    
    scanf("%d%d", &V, &Q);
    range.resize(V+10);
    
    for(int i = 1; i <= V; ++i)
        scanf("%llu", &color[i]);
    
    for(int i = 1; i < V; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1);
    init(1, 1, V);
    
    while(Q--) {
        scanf("%d", &t);
        
        if(t == 1) {
            scanf("%d%d", &u, &newColor);
            ConvertUpdate(u, newColor, V);
        }
        else {
            scanf("%d", &u);
            printf("%d\n", ConvertQuery(u, V));
        }
    }
    
    return 0;
}
