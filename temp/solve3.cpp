#include <bits/stdc++.h>
using namespace std;


void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos] = h[l];
        return;
    }
    
    int mid = (l+r)>>1;
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
    tree[pos] = min(tree[pos<<1], tree[pos<<1|1]);
}


int query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l)
        return 1e9;
    
    if(L <= l && r <= R)
        return tree[pos];
    
    int mid = (l+r)>>1;
    return min(query(pos<<1, l, mid, L, R), query(pos<<1|1, mid+1, r, L, R));
}



