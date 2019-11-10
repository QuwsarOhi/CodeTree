Tree:
	* DFS timing
	* Least Common Ancestor
    * Least Common Ancestor with changed root
    * Child Check
    * Overlapped path between two paths of a tree
    * Number of edges between path[a, b] if two nodes[c, d] of a tree is joined
    * Subtree range update and range query with a changed root
    * Finding LCA of more than two nodes in a set [supports insert/erase nodes, edge count]
    * Heavy Light Decomposition of tree path updates and queries
    * DSU on tree [Sack/Guni]

/* sTime/in  : starting time of node n
   eTime/out : finishing time of node n
     1   
    / \
   5   6
      / \
     7   4
        / \
       2   3
discover_nodes/revIn : {1, 5, 6, 7, 4, 2, 3}
sTime[]/in[]  : {1, 6, 7, 5, 2, 3, 4}               index starts from 1, 
eTime[]/out[] : {7, 6, 7, 7, 2, 7, 4}               i'th index contains start time of i'th node
Calculate Child : 
for node 6 : childs are in range sTime[6] - eTime[6] : 3 - 7
so child nodes are : 6, 7, 4, 2, 3 (discover node index range)
we don't need discover time vector to calculate distance
notice, if we only update with sTime and eTime, the range update will always be right 
range updates can be performed in range of start time and end time of a node */

/* ----------------------------- DFS Timing, Child Finding, LCA----------------------------- */
int cnt = 0;														   // cnt is used for timer
void dfs(int u, int p) {
    in[u] = ++cnt;
    revIn[cnt] = u, par[u][0] = p, lvl[u] = lvl[p]+1;
   	for(int i = 1; i <= 20; ++i) par[u][i] = par[par[u][i-1]][i-1];				// used for LCA
    for(auto v : G[u]) { if(v != p) dfs(v, u); }
    out[u] = cnt;
} int LCA(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    for(int p = 20; p >= 0; --p) {
        if(lvl[u] - (1 << p) >= lvl[v]) u = par[u][p];
    } if(u == v) return u;
    for(int p = 20; p >= 0; --p) { if(par[u][p] != par[v][p]) u = par[u][p], v = par[v][p]; }
    return par[u][0];
} int dist(int a, int b) {
    return lvl[a] + lvl[b] - 2*LCA(a, b);
}
// LCA if the root changes, [first dfs is done with root 1 or any other fixed node]
int LCA(int u, int v, int root) {							// root is the new root of the tree
    if(isChild(u, root) and isChild(v, root))	return LCA(u, v);
    if(isChild(u, root) != isChild(v, root))	return root;
    int x = LCA(u, v), y = LCA(u, root), z = LCA(v, root);
    int a = lvl[root] - lvl[x], b = lvl[root] - lvl[y], c = lvl[root] - lvl[z];
    if(a <= b and a <= c) return x;
    if(b <= a and b <= c) return y;
    return z;
} 
// Check if one node is child of another node
bool isChild(int child, int par) {                         // returns true if a is child of b
    return ((child == par) or ((in[par] <= in[child]) and (out[par] >= out[child])));
}
// a is upper node (lower level) of path a-b and c is upper node (lower level) of path c-d
// path a-b and c-d overlaps iff b is a child of c or d or both of c&d
pii overlapPath(int a, int b, int c, int d) {   // returns number of common path of c-d and a-b
    if(not isChild(b, c)) return {0, 0};
    int u = LCA(b, d);                   // u is the lowest point on which c-d and a-b overlaps
    if(level[a]>level[c])   { if(isChild(u, a)) return {a, u}; }
    else                    { if(isChild(u, c)) return {c, u}; }                // c is above a
    return {0, 0};                                                      // no common path found
}
// Finds number of edges if we join nodes a, b and want to find path from c to d
int EdgeCount(int a, int b, int c, int d) {              
    int u = LCA(a, b), int v = LCA(c, d);           // connected paths are u->a & u->b
    int ans = distance(c, d, v);                    // query paths are v->c & v->d
    pii tt;                                                              // cases:
    tt = overlapPath(v, c, u, a);                                        // u->a overlaps v->c
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    tt = overlapPath(v, c, u, b);                                        // u->a overlaps v->d
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    tt = overlapPath(v, d, u, a);                                        // u->b overlaps v->c
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    tt = overlapPath(v, d, u, b);                                        // u->b overlaps v->d
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    return ans;
}
/* ---------------------- Subtree update and query with changed root ----------------------- */
void subTreeUpdate(int u, int root, int val) {              // Subtree update with changed root
    if(u == root)               DS.update(in[1], out[1], val);
    else if(isChild(u, root))   DS.update(in[u], out[u], val);
    else if(isChild(root, u)) {
        int x = getChild(root, u);
        DS.update(in[1], out[1], val), DS.update(in[x], out[x], -val);
    } else DS.update(in[u], out[u], val);
}
// Subtree update with changed root      [the root of update and query doesn't have to be same]
ll getSubTreeSum(int u, int root) {
    if(u == root)           return DS.query(in[1], out[1]);
    if(isChild(u, root))    return DS.query(in[u], out[u]);
    else if(isChild(root, u)) {
        int x = getChild(root, u);
        return DS.query(in[1], out[1]) - DS.query(in[x], out[x]);
    } else return DS.query(in[u], out[u]);
}

/* ----------------------------------- LCA of a subset ----------------------------------- */
// Given a tree, you have to find the LCA of a subset of nodes from the dree
struct LCATree {
    int lca, n, cost;                               // current lca, number of nodes, total edge
    SegTree DS;                                     // DS contains point update and range query
    set<int>nodes;
    void init(int sz) { n = sz, lca = -1, cost = 0; }
    int getPar(int u, int p) {
        for(int i = 20; i >= 0; --i) { if(p & (1 << i)) u = par[u][i]; } // parent sparse table
        return u;
    } int LCA() {
        int u = *nodes.begin(), tot = nodes.size(), v, ret = *nodes.begin();
        int lo = 0, hi = lvl[u]-1;
        while(lo <= hi) {
            int mid = (lo+hi)>>1, v = getPar(u, mid);
            if(DS.query(1, 1, n, in[v], out[v]) == tot)     hi = mid-1, ret = v;
            else                                            lo = mid+1;
        } return ret;
    } int findChainPar(int u, int t) {                      // finds parent node of u having 
        int lo = 0, hi = lvl[u]-1, ret = u, v, mid;         // active child node more than t
        while(lo <= hi) {
            mid = (lo+hi)>>1, v = getPar(u, mid);
            if(DS.query(1, 1, n, in[v], out[v]) > t)    hi = mid-1, ret = v;
            else                                        lo = mid+1;
        } return ret;
    } void addNode(int u) {
        int pstLca = lca;
        nodes.insert(u), DS.update(1, 1, n, in[u], 1);
        if(lca == -1) { lca = u; return; }
        else lca = LCA();
        if(pstLca == lca and query(1, 1, n, in[u], out[u]) == 1) {
            int v = findChainPar(u, 1);   // new LCA is same but the node is on different chain
            cost += lvl[u] - lvl[v];
        } else if(lca != pstLca)  // new LCA changes, newLCA will always be upper from past LCA
            cost += lvl[u] + lvl[pstLca] - 2*lvl[lca]; // also the node u is on different chain
    } void removeNode(int u) {
        int pstLca = lca;
        nodes.erase(u), DS.update(1, 1, n, in[u], -1);
        if(nodes.empty())   { lca = -1, cost = 0; return; }
        else                lca = LCA();
        if(pstLca == lca and query(1, 1, n, in[u], out[u]) == 0) {
            int v = findChainPar(u, 0);
            cost -= lvl[u] - lvl[v];
        } else if(lca != pstLca)
            cost -= lvl[lca] + lvl[u] - 2*lvl[pstLca];
}};

/* Heavy Light Decomopse
   Tree path update/query, there are total log(n) linear chains of a tree */
int parent[MAX], level[MAX], nextNode[MAX], chain[MAX], num[MAX], val[MAX], numToNode[MAX];
int top[MAX], ChainSize[MAX], mx[MAX], ChainNo = 1, all = 1, n;
void dfs(int u, int Parent) {
    parent[u] = Parent, ChainSize[u] = 1;              
    for(auto v : G[u]) {
        if(v == Parent)  continue;
        level[v] = level[u]+1;  
        dfs(v, u);
        ChainSize[u] += ChainSize[v];
        if(nextNode[u] == -1 || ChainSize[v] > ChainSize[nextNode[u]]) nextNode[u] = v;
}} void hld(int u, int Parent) {
    chain[u] = ChainNo, num[u] = all++; // Giving each nodes a chain number and numbering nodes
    if(ChainSize[ChainNo] == 0) top[ChainNo] = u;                        // first node of chain
    ChainSize[ChainNo]++;
    if(nextNode[u] != -1) hld(nextNode[u], u);                    // Next max chain node exists
    for(auto v : G[u]) {
        if(v == Parent || v == nextNode[u])  continue;
        ++ChainNo; hld(v, u);
}} int GetSum(int u, int v) {
    int res = 0;
    while(chain[u] != chain[v]) {                      // While two nodes are not in same chain
        if(level[top[chain[u]]] < level[top[chain[v]]]) swap(u, v);    // u is the deeper chain
        int start = top[chain[u]];
        res += query(1, 1, n, num[start], num[u]);          // Run query in u node's chain
        u = parent[start];                                  // go to the upper chain of u
    } if(num[u] > num[v]) swap(u, v);
    res += query(1, 1, n, num[u], num[v]);
    return res;
} void updateNodeVal(int u, int val) {
    update(1, 1, n, num[u], val);                                // Updating the value of chain
} void numToNodeConv(int n) {
    for(int i = 1; i <= n; ++i) numToNode[num[i]] = i;          // build DS using the num[node]
} int main() {                                      // Driver function of HLD
    memset(nextNode, -1, sizeof nextNode);
    ChainNo = 1, all = 1; dfs(1, 1);
    memset(ChainSize, 0, sizeof ChainSize);         // array reused in hld
    hld(1, 1); numToNodeConv(n);
    init(1, 1, n);                                  // initialize DS
}

/* ------------------------------------- DSU on TREE ------------------------------------- */
int sz[maxn];
void getsz(int v, int p){
    sz[v] = 1;                                      // every vertex has itself in its subtree
    for(auto u : G[v]) if(u != p) { getsz(u, v); sz[v] += sz[u]; } 
}                                                   // add size of child u to its parent(v)
// Heavy-Light-Decomposition Style: nlogn
int cnt[maxn];
bool big[maxn];
void add(int v, int p, int x) {                     // The operation function
    cnt[col[v]] += x;                               // Perform required operation here
    for(auto u: G[v]) 
        if(u != p and not big[u]) 
            add(u, v, x);
} void dfs(int v, int p, bool keep) {        // node, parent, keep the node after dfs execution
    int mx = -1, bigChild = -1;
    for(auto u : G[v])                                  // finding big child with maximum nodes
       if(u != p && sz[u] > mx)      mx = sz[u], bigChild = u;        
    for(auto u : G[v])                          //  dfs on small childs and clear them from cnt
        if(u != p && u != bigChild)  dfs(u, v, 0);  
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;     // bigChild marked and not cleared from cnt
    add(v, p, 1);
// Answer execution : cnt[c] is the number of vertices in subtree of vertex v that has color c.
    if(bigChild != -1)  big[bigChild] = 0;
    if(keep == 0)       add(v, p, -1);
}
// Map Style: n(logn)^2
map<int, int> *cnt[maxn];
void dfs(int v, int p){
    int mx = -1, bigChild = -1;
    for(auto u : G[v]) {
       if(u != p) {
           dfs(u, v);
           if(sz[u] > mx) mx = sz[u], bigChild = u;
    }} 
    if(bigChild != -1)  cnt[v] = cnt[bigChild];                   // Copies pointer of bigchild 
    else                cnt[v] = new map<int, int> ();        // Create empty pointer container
    (*cnt[v])[ col[v] ] ++;
    for(auto u : G[v])
       if(u != p && u != bigChild) {
           for(auto x : *cnt[u]) (*cnt[v])[x.first] += x.second;
       } // (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. 
}
// Vector Style: nlogn
vector<int> *vec[maxn];
int cnt[maxn];
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : G[v]) { if(u != p && sz[u] > mx) mx = sz[u], bigChild = u; }  // bigChild mark
    for(auto u : G[v]) { if(u != p && u != bigChild)  dfs(u, v, 0); }       // traverse non big 
    if(bigChild != -1) { dfs(bigChild, v, 1), vec[v] = vec[bigChild]; }        // pointer copy
    else               { vec[v] = new vector<int> (); }
    vec[v]->push_back(v), cnt[ col[v] ]++;
    for(auto u : G[v])
       if(u != p && u != bigChild)
           for(auto x : *vec[u]) { cnt[ col[x] ]++, vec[v] -> push_back(x); }
    // (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c.
    if(keep == 0) { for(auto u : *vec[v]) cnt[col[u]]--; }
}

