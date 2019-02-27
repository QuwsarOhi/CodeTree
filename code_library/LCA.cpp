// LCA
// Least Common Ancestor with sparse table

void dfs(int u, int p) {
    in[u] = ++cnt;
    revIn[cnt] = u, par[u][0] = p, lvl[u] = lvl[p]+1;
    
    for(int i = 1; i <= 20; ++i)
        par[u][i] = par[par[u][i-1]][i-1];
    
    for(auto v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = cnt;
}

int LCA(int u, int v) {
    if(lvl[u] < lvl[v]) swap(u, v);
    for(int p = 20; p >= 0; --p)
        if(lvl[u] - (1 << p) >= lvl[v])
            u = par[u][p];
    if(u == v) return u;
    for(int p = 20; p >= 0; --p)
        if(par[u][p] != par[v][p])
            u = par[u][p], v = par[v][p];
    return par[u][0];
}

// LCA if the root changes, [first dfs is done with root 1 or any other fixed node]
int LCA(int u, int v, int root) {
    if(isChild(u, root) and isChild(v, root))
        return LCA(u, v);
    if(isChild(u, root) != isChild(v, root))
        return root;
    int x = LCA(u, v), y = LCA(u, root), z = LCA(v, root);
    int a = lvl[root] - lvl[x], b = lvl[root] - lvl[y], c = lvl[root] - lvl[z];
    if(a <= b and a <= c) return x;
    if(b <= a and b <= c) return y;
    return z;
}

// --------------------------- LCA WITH Sparse Table Vector --------------------------- 
// DFS and LCA INIT is same
void MERGE(vector<int>&u, vector<int>&v) {          // Do what is to be done to merge
    for(auto it : v) u.push_back(it);               // here taking lowest 10 values
    sort(u.begin(), u.end());
    while((int)u.size() > 10)
        u.pop_back();
}

vector<int> W[MAX][20];             // W[u][0] will contain initial weight/weights at node u
vector<int> LCA(int u, int v) {
    vector<int> T;
    if(level[u] > level[v]) swap(u, v);     // v is deeper
    int p = ceil(log2(level[v]));
    for(int i = p ; i >= 0; --i)            // Pull up v to same level as u
        if(level[v] - (1LL<<i) >= level[u]) {
            MERGE(T, W[v][i]);
            v = sparse[v][i];
        }   
    if(u == v) {                                // if u WAS the parent
        MERGE(T, W[u][0]);
        return T;
    }
    for(int i = p; i >= 0; --i)                                         // Pull up u and v together while LCA not found
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i]) {        // -1 check is if 2^i is out of calculated range
            MERGE(T, W[u][i]);
            MERGE(T, W[v][i]);
            u = sparse[u][i], v = sparse[v][i];
        }
    MERGE(T, W[u][0]);              // As W[x][0] denoted the x nodes weight
    MERGE(T, W[v][0]);              // every sparse node must be calculated
    MERGE(T, W[sparse[v][0]][0]);   // we can also calculate summation of distance like this
    return T;
}

// --------------------------- Overlap Path of Tree --------------------------- 

// Note: DfsTiming and isChild function required
// a is upper node of path a-b and c is upper node of path c-d
pii overlapPath(int a, int b, int c, int d) {      // returns number of common path of c-d and a-b
    // path a-b and c-d overlaps iff b is a child of c or d or both of c&d
    if(not isChild(b, c)) return {0, 0};
    int u = LCA(b, d);              // u is the lowest point on which c-d and a-b overlaps
    if(level[a]>level[c]) {             // a is below c 
        if(isChild(u, a))           // also u is child of a
            return {a, u};
    }
    else {                          // c is above a
        if(isChild(u, c))
            return {c, u};
    }
    return {0, 0};                  // no common path found
}

int EdgeCount(int a, int b, int c, int d) {             // Finds number of edges if we join nodes a, b and 
    a = Convert(a), b = Convert(b), c = Convert(c), d = Convert(d); // want to find path from c to d
    int u = LCA(a, b);
    int v = LCA(c, d);
    int ans = dist(c, d, v);
    pii tt;
    // connected paths are u->a & u->b
    // query paths are v->c & v->d
    // cases:
    // u->a overlaps v->c
    tt = overlapPath(v, c, u, a);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    // u->a overlaps v->d
    tt = overlapPath(v, c, u, b);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    // u->b overlaps v->c
    tt = overlapPath(v, d, u, a);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    // u->b overlaps v->d
    tt = overlapPath(v, d, u, b);
    ans -= tt.fi == 0? 0:dist(tt.fi, tt.se, LCA(tt.fi, tt.se));
    return ans;
}

// ----- return k'th node if we traverse from node u to v of a tree

// NOT TESTED!!
int getKthNode(int u, int v, int k, int lca) {
    int lftChain = lvl[u] - lvl[lca] + 1;
    int rhtChain = lvl[v] - lvl[lca];
    if(k == 1) return u;
    if(lca == v) {
        for(int i = 20; i >= 0; --i)
            if(k - (1 << i) >= 1)
                u = par[u][i], k -= (1 << i);
        return u;
    }
    if(lca == u) {
        k = rhtChain+1-k;
        for(int i = 20; i >= 0; --i)
            if(k - (1 << i) >= 0)
                v = par[v][i], k -= (1 << i);
        return v;
    }
    if(k > lftChain) {
        k -= lftChain;
        k = rhtChain - k;
        for(int i = 20; i >= 0; --i)
            if(k - (1 << i) >= 0)
                v = par[v][i], k -= (1 << i);
        return v;
    }
    for(int i = 20; i >= 0; --i)
        if(k - (1 << i) >= 1)
            u = par[u][i], k -= (1 << i);
    return u;
}

// -------- SUBTREE UPDATE FUNCTIONS --------
// if the root changes

void subTreeUpdate(int u, int root, int val) {
    // if u is child of root, then subtree of u
    if(u == root)
        DS.update(in[1], out[1], val);
    else if(isChild(u, root))
        DS.update(in[u], out[u], val);
    // if root is child of u
    else if(isChild(root, u)) {
        int x = getChild(root, u);      // get the first child of u
        DS.update(in[1], out[1], val);
        DS.update(in[x], out[x], -val);
    }
    else
        DS.update(in[u], out[u], val);
}

ll getSubTreeSum(int u, int root) {
    // if u is child of root, then subtree of u
    if(u == root)
        return DS.query(in[1], out[1]);
    if(isChild(u, root))
        return DS.query(in[u], out[u]);
    // if root is child of u
    else if(isChild(root, u)) {
        int x = getChild(root, u);      // get the first child of u
        return DS.query(in[1], out[1]) - DS.query(in[x], out[x]);
    }
    else
        return DS.query(in[u], out[u]);
}


// ------- Can Give Total Spanning Tree edges for an particular set of nodes

set<int>nodes;                  // contains nodes according to dfs order
int nodeCost(int u) {           // returns node Query/Insert updated distance    
    auto it = nodes.insert(in[u]).first;        // inserted according to dfs in-timing
    auto l = it, r = it;                        // iterator of the inserted index
    if(it == nodes.begin())
        l = --nodes.end();
    else --l;
    
    if(it == --nodes.end())
        r = nodes.begin();
    else ++r;
    
    int L = revIn[*l], R = revIn[*r];     // nodes are retrieved from dfs in-timing 
    
    // dst is the spanning distance if the new node is added
    int dst = lvl[u] + lvl[LCA(L, R)] - lvl[LCA(u, L)] - lvl[LCA(u, R)];
    return dst;
}

void removeNode(int u) {
    nodes.erase(in[u]);
}
