// SPOJ - QTREE3 - Query on a tree again!
// http://www.spoj.com/problems/QTREE3/

// Segment Tree + HLD

#include <bits/stdc++.h>
#define MAX 110000
using namespace std;
typedef long long ll;

const int INF = 1e8;
int parent[MAX], nextNode[MAX], level[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX], top[MAX], ChainSize[MAX], ChainNo = 1, all = 1;
vector<int>G[MAX];

struct SegTreeHLD {
    vector<pair<int, int> >tree;        // level, nodeNo
    
    void Resize(int n) {
        tree.resize(n*5);
    }
    
    void init(int pos, int l, int r) {
        if(l == r) {
            tree[pos] = {INF, numToNode[l]};
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid);
        init(pos<<1|1, mid+1, r);
        tree[pos] = min(tree[pos<<1], tree[pos<<1|1]);
    }
    
    void update(int pos, int l, int r, int idx, int val) {
        if(l == r) {
            if(tree[pos].first == INF)
                tree[pos].first = val;
            else
                tree[pos].first = INF;
            return;
        }
        
        int mid = (l+r)>>1;
        if(idx <= mid)
            update(pos<<1, l, mid, idx, val);
        else
            update(pos<<1|1, mid+1, r, idx, val);
        
        tree[pos] = min(tree[pos<<1], tree[pos<<1|1]);
    }
    
    pair<int, int> query(int pos, int l, int r, int L, int R) {
        if(r < L || R < l)
            return {INF, INF};
        
        if(L <= l && r <= R)
            return tree[pos];
        
        int mid = (l+r)>>1;
        return min(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
    }
};


// Heavy Light Decomposition Start
void dfs(int u, int Parent) {
    parent[u] = Parent;             // Parent of u
    ChainSize[u] = 1;               // Number of child (initially the size is 1, contains only 1 node. itself) (resued array in hld)
    
    for(int i = 0; i < int(G[u].size()); ++i) {
        int v = G[u][i];
        if(v == Parent)             // if the connected node is parent, skip
            continue;
        level[v] = level[u]+1;      // level of the child node is : level of parent node + 1
        dfs(v, u);
        ChainSize[u] += ChainSize[v];         // Increment the child numbers
        if(nextNode[u] == -1 || ChainSize[v] > ChainSize[nextNode[u]])
            nextNode[u] = v;            // next selected node of u (select the node which has more child, (HEAVY))
    }
}

void hld(int u, int Parent) {
    chain[u] = ChainNo;                 // Chain Number
    num[u] = all++;                     // Numbering all nodes
    
    if(ChainSize[ChainNo] == 0)         // if this is the first node
        top[ChainNo] = u;               // mark this as the root node of the n'th chain
        
    ChainSize[ChainNo]++;
    
    if(nextNode[u] != -1)               // if this node has a child, go to it
        hld(nextNode[u], u);            // the next node is included in the chain
    
    for(int i = 0; i < int(G[u].size()); ++i) {
        int v = G[u][i];
        if(v == Parent || v == nextNode[u])     // if this node is parent node or, this node is already included in the chain, skip
            continue;
        ChainNo++;                          // this is a new (light) chain, so increment the chain no. counter
        hld(v, u);
    }
}

void numToNodeConv(int n) {
    for(int i = 1; i <= n; ++i)
        numToNode[num[i]] = i;
}


SegTreeHLD stree;

int main() {
    int u, v, n, q, typ;
    scanf("%d%d", &n, &q);
    
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    memset(nextNode, -1, sizeof nextNode);
    dfs(1, -1);
    memset(ChainSize, 0, sizeof ChainSize);
    hld(1, -1);
    numToNodeConv(n);
    stree.Resize(n);
    stree.init(1, 1, n);
    
    while(q--) {
        scanf("%d%d", &typ, &v);
        
        if(typ == 0)
            stree.update(1, 1, n, num[v], level[v]);
        else {
            pair<int, int> ans = {INF, INF};
            while(chain[v] != 1) {
                int chainParent = top[chain[v]];
                ans = min(stree.query(1, 1, n, num[chainParent], num[v]), ans);
                v = parent[chainParent];
            }
            
            ans = min(stree.query(1, 1, n, num[1], num[v]), ans);
            
            if(ans.first == INF)
                printf("-1\n");
            else
                printf("%d\n", ans.second);
        }
    }
    
    return 0;
}
