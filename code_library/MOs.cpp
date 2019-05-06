// MO's Algo
// Complexity : (N+Q)*sqrt(N)

struct query {
    int l, r, id;
};

// block must be declared as const, as compilers do fast division with const values
const int block = 320;          // For 100000
query q[MAX];
int ans[MAX];

// MO's Tree Ordering
bool cmp(query &a,query &b){                       // Faster Comparison function
	if(a.l/block !=b.l/block)   return a.l < b.l;
	if((a.l/block)&1)           return a.r < b.r;
	return a.r > b.r;
}

void add(int x) {}       // Add x'th value in range 
void remove(int x) {}    // Remove x'th value from range   

void MOs() {  
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        ans[q[i].id] =                      // Add Constraints
}}

/* MOs on Tree [Subtree] */

int timer = -1;
void dfs(int u, int p = 0) {        // MO's Sub-Tree DFS Timing
    in[u] = ++timer;
    ID[timer] = u;
    for(auto v : G[u])
        if(v != p) dfs(v, u);
    out[u] = timer;
    ID[timer] = u;
}
// Sort subtree parents according to l = in[u] and r = out[u]
// Apply MOs in the [l, r] range, adding and removing is same as above


/* MOs on Tree [Tree Path] */

struct query {
    int id, ut, vt, lca;        // timing of node u, node v and lca of (u & v)
} q[MAX];

int timer = -1;
void dfs(int u, int p = 0) {    // DFS timing
    in[u] = ++timer;            // Also need to calculate LCA
    ID[timer] = u;
    for(auto v : G[u])
        if(v != p) dfs(v, u);
    out[u] = ++timer;
    ID[timer] = u;
}

bitset<MAX> proc;
void process(int ut) {          
    if(proc[ID[ut]]) {}     // if proc = 0, then add the node and set proc = 1
    else             {}     // else remove the node and set proc = 0
}

void MOs_Tree() {
    for(int i = 0, j = 0; j < Q; ++i, ++j) {        // Input Processing
        scanf("%d%d", &u, &v);
        q[i].id = i, q[i].lca = LCA(u, v);
        if(in[u] > in[v]) swap(u, v);
        
        if(q[i].lca == u)
            q[i].ut = in[u], q[i].vt = in[v];
        else
            q[i].ut = out[u], q[i].vt = in[v];
    }
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].ut)   proccess(--l);
        while(r < q[i].vt)   proccess(++r);
        while(l < q[i].ut)   proccess(l++);
        while(r > q[i].vt)   proccess(r--);

        u = ID[l], v = ID[r];
        if(q[i].lca != u and q[i].lca != v) proccess(in[q[i].lca]);
        ans[q[i].id] =      // Calculate the answer
        if(q[i].lca != u and q[i].lca != v) proccess(in[q[i].lca]);
}}