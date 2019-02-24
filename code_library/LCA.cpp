// LCA
// Least Common Ancestor with sparse table

vl G[MAX], W[MAX];
int level[MAX], parent[MAX], sparse[MAX][20];
ll dist[MAX], DIST[MAX][20];

void dfs(int u, int par, int lvl, ll d) {           // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                                
    dist[u] = d;                                    // remove distance if not needed
    for(int i = 0; i < (int)G[u].size(); ++i)
        if(parent[u] != G[u][i])
            dfs(G[u][i], u, lvl+1, d+W[u][i]);
}

void LCAinit(int V) {
    memset(parent, -1, sizeof parent);
    dfs(0, -1, 0);                               // DFS first
    memset(sparse, -1, sizeof sparse);              // Main initialization of sparse table LCA starts here
    for(int u = 1; u <= V; ++u)                     // node u's 2^0 parent
        sparse[u][0] = parent[u];
    for(int p = 1, v; (1LL<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}

int LCA(int u, int v) {
    if(level[u] > level[v]) swap(u, v);         // v is deeper
    int p = ceil(log2(level[v]));
    
    for(int i = p ; i >= 0; --i)                // Pull up v to same level as u
        if(level[v] - (1LL<<i) >= level[u])
            v = sparse[v][i];
    if(u == v) return u;                // if u WAS the parent

    for(int i = p; i >= 0; --i)                                     // Pull up u and v together while LCA not found
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    return parent[u];
}

// --------------------------- LCA WITH DISTANCE --------------------------- 
void distDP(int V) {                    // initialiser for LCA_with_DIST, call after LCAinit()
    for(int u = 1; u <= V; ++u)         // NOTE : DIST[u][0] = weight of node u
        DIST[u][0] = W[u];              // Where W[u] = weight of node u
    for(int p = 1; (1<<p)<=V; ++p)
        for(int u = 1; u <=V; ++u) {
            int v = sparse[u][p-1];
            if(v == -1) continue;
            DIST[u][p] += DIST[u][p-1] + DIST[v][p-1];
}}

int LCA_with_DIST(int u, int v, long long &w) {     // w retuns distance from u -> v
    w = 0;
    if(level[u] > level[v]) swap(u, v);             // v is deeper
    int p = ceil(log2(level[v]));
    for(int i = p ; i >= 0; --i)                    // Pull up v to same level as u
        if(level[v] - (1LL<<i) >= level[u]) {
            w += DIST[v][i];
            v = sparse[v][i];
        }
    if(u == v) {                                    // if u WAS the parent
        w += DIST[v][0];
        return u;
    }
    for(int i = p; i >= 0; --i)                     // Pull up u and v together while LCA not found
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    w += DIST[v][0];
    w += DIST[u][0];
    w += DIST[sparse[v][0]][0];
    return parent[u];
}

ll Distance(int u, int v) {
    int lca = LCA(u, v);
    return dist[v] + dist[u] - 2*dist[lca];
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

// NOT TESTED!!
// return k'th node if we traverse from node u to v of a tree
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