// MO's Algo
// Complexity : Q*sqrt(N)

struct query {
    int l, r, id;
};

const int block = 320;          // For 100000
query q[MAX];
int ans[MAX];

bool cmp(query &a, query &b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}

void add(int x) {}       // Add x'th value in range 
void remove(int x) {}    // Remove x'th value from range   

int main() {  
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
