// SPOJ
// LITE (Segment Tree Laze Propagation)

#include <bits/stdc++.h>
using namespace std;


struct node {
    int val, prop;
};

// Prop :
// 0 : No prop operation
// 1 : Prop operation should be done

node tree[409000];

void init(int L, int R, int pos) {
    if(L == R) {
        tree[pos].val = 0;
        tree[pos].prop = 0;
        return;
    }
    
    int mid = (L+R)>>1;
    
    init(L, mid, pos<<1);
    init(mid+1, R, pos<<1|1);

    tree[pos].val = tree[pos].prop = 0;
}

int flipProp(int parentVal, int childVal) {
    if(parentVal == childVal)
        return 0;
    return parentVal;
}

void propagate(int L, int R, int pos) {
    if(tree[pos].prop == 0 || L == R)       // If no propagation tag
        return;                             // or leaf node, then no need to change
    
    int mid = (L+R)>>1;
    tree[pos<<1].val = (mid-L+1) - tree[pos<<1].val;                    // Set left & right child value
    tree[pos<<1|1].val = (R-mid) - tree[pos<<1|1].val;
    
    tree[pos<<1].prop = flipProp(tree[pos].prop, tree[pos<<1].prop);    // Flip child prop according to problem
    tree[pos<<1|1].prop = flipProp(tree[pos].prop, tree[pos<<1|1].prop);
    tree[pos].prop = 0;                                                 // Clear parent propagation tag
}

void update(int L, int R, int l, int r, int pos) {
    if(r < L || R < l)
        return;
    
    propagate(L, R, pos);
    if(l <= L && R <= r) {
        tree[pos].val = (R-L+1) - tree[pos].val;    // Value updated
        tree[pos].prop = 1;                         // Propagation tag set
        return;
    }
    
    int mid = (L+R)>>1;
    update(L, mid, l, r, pos<<1);
    update(mid+1, R, l, r, pos<<1|1);
    tree[pos].val = tree[pos<<1].val + tree[pos<<1|1].val;
}

int querySum(int L, int R, int l, int r, int pos) {
    if(r < L || R < l)
        return 0;
        
    propagate(L, R, pos);
    if(l <= L && R <= r)
        return tree[pos].val;
    
    int mid = (L+R)>>1;
    int lft = querySum(L, mid, l, r, pos<<1);
    int rht = querySum(mid+1, R, l, r, pos<<1|1);
    return lft+rht;
}



int main() {
    int n, q, c, l, r;
    scanf("%d %d", &n, &q);
    
    init(1, n, 1);
    while(q--) {
        scanf("%d %d %d", &c, &l, &r);
        if(c == 0)
            update(1, n, l, r, 1);
        else
            printf("%d\n", querySum(1, n, l, r, 1));
    }
    return 0;
}
