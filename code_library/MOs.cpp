// MO's Algo
// Complexity : (N+Q)*sqrt(N)

struct query {
    int l, r, id;
};


// block must be declared as const, as compilers do fast division with const values
const int block = 320;          // For 100000
query q[MAX];
int ans[MAX];

bool cmp(query &a,query &b){                       // Faster Comparison function
	if(a.l/block !=b.l/block)   return a.l < b.l;
	if((a.l/block)&1)           return a.r < b.r;
	return a.r > b.r;
}

// MO's Tree Ordering
bool cmp(query &a,query &b) {
    if(a.l/block !=b.l/block)   return a.l < b.l;
    return a.r < b.r;
}

// MO's Sub-Tree DFS Timing
int timer = -1;
void dfs(int u, int p) {
    in[u] = ++timer;
    node.push_back(u);
    for(auto v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = timer;
}

void add(int x) {}       // Add x'th value in range 
void remove(int x) {}    // Remove x'th value from range   

int main() {  
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {                // Query input
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l, --q[i].r, q[i].id = i;        // NOTE : value index starts from 0
    }
    
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        ans[q[i].id] =                      // Add Constraints
    }  
    return 0;
}
