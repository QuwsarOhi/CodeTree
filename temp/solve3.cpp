#include <bits/stdc++.h>
#define MAX 110000
using namespace std;

struct MergeSortTree {
    vector<int>tree[MAX*4];
    void init(int pos, int l, int r, int val[]) {
        tree[pos].clear();                              // Clears past values
        if(l == r) {
            tree[pos].push_back(val[l]);
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }
    int query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R)
            return (int)(upper_bound(tree[pos].begin(), tree[pos].end(), k) - lower_bound(tree[pos].begin(), tree[pos].end(), k));        // MODIFY
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
}};


vector<int>G[MAX];
int timer = 0, sparse[MAX][22], lvl[MAX], st[MAX], ed[MAX];
MergeSortTree T;

void dfs(int u, int level = 0) {
    ++timer;
    st[u] = timer;
    lvl[timer] = level;

    for(auto v : G[u]) {
        if(st[v] != 0) continue;
        dfs(v, level+1);
    }

    ed[u] = timer;
}

int BinaryLift(int u, int k) {
    for(int i = 0; i < 30 and u > 0; ++i)
        if(k&(1<<i)) u = sparse[u][i];
    return u;
}

int main() {
    int n, v, p, q;
    scanf("%d", &n);
    memset(sparse, -1, sizeof sparse);
    
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p);
        if(p != 0) {
            G[i].push_back(p);
            G[p].push_back(i);
            sparse[i][0] = p;
        }
    }

    for(int p = 1; (1 << p) <= n; ++p)
        for(int u = 1; u <= n; ++u)
            if(sparse[u][p-1] > 0)
                sparse[u][p] = sparse[sparse[u][p-1]][p-1];

    for(int i = 1; i <= n; ++i)
        if(st[i] == 0)
            dfs(i, 1);
    T.init(1, 1, n, lvl);
    cin >> q;
    
    while(q--) {
        scanf("%d%d", &v, &p);
        int u = BinaryLift(v, p);
        //cerr << "Par " << u << endl;
        if(u == -1 or u == v)
            printf("0 ");
        else {
            //cerr << st[u] << ", " << ed[u] << ", " << lvl[v] << endl;
            printf("%d ", T.query(1, 1, n, st[u], ed[u], lvl[v])-1);
        }
    }


    return 0;
}