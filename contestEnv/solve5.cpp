

#include <bits/stdc++.h>
#define MAX 110000
using namespace std;

// CS Academy Candles :https://csacademy.com/contest/archive/task/candles/statement/
struct SortedST {                                       // Performs -1 from n nodes and keeps nodes sorted (descending order)
    struct node { int val, prop; };
    node tree[5*MAX];
    void init(int pos, int l, int r, int val[]) {       // val[] must be sorted from hi to low
        if(l == r) {
            tree[pos].val = val[l];
            tree[pos].prop = 0;
            return;
        }
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val), init(pos<<1|1, mid+1, r, val);
        tree[pos].val = max(tree[pos<<1].val, tree[pos<<1|1].val);
        tree[pos].prop = 0;
    }
    void propagate(int pos, int l, int r) {
        if(tree[pos].prop == 0 || l == r) {
            tree[pos].prop = 0;
            return;
        }
        tree[pos<<1|1].prop += tree[pos].prop;
        tree[pos<<1].prop += tree[pos].prop;
        tree[pos<<1].val += tree[pos].prop;
        tree[pos<<1|1].val += tree[pos].prop;
        tree[pos].val = max(tree[pos<<1].val, tree[pos<<1|1].val);
        tree[pos].prop = 0;
    }
    int findVal(int pos, int l, int r, int idx) {               // Finds value in index idx
        if(l == r) return tree[pos].val;
        propagate(pos, l, r);    
        int mid = (l+r)>>1;
        if(idx <= mid)  return findVal(pos<<1, l, mid, idx);
        else            return findVal(pos<<1|1, mid+1, r, idx);
    }
    void update(int pos, int l, int r, int L, int R, int val) {
        if(r < L || R < l) return;
        propagate(pos, l, r);
        if(L <= l && r <= R) {
            tree[pos].val += val;
            tree[pos].prop += val;
            return;
        }
        int mid = (l+r)>>1;
        update(pos<<1, l, mid, L, R, val);
        update(pos<<1|1, mid+1, r, L, R, val);
        tree[pos].val = max(tree[pos<<1].val, tree[pos<<1|1].val);
    }
    int rightMost(int pos, int l, int r, int val) {             // Finds rightmost value in tree that contains val
        if(l == r) return l;
        if(tree[pos].val < val) return 0;
        propagate(pos, l, r);
        int mid = (l+r)>>1;
        if(tree[pos<<1|1].val >= val) return rightMost(pos<<1|1, mid+1, r, val);
        return rightMost(pos<<1, l, mid, val);
    }
    bool MinusQuery(int q, int n) {                             // Decreases q nodes by 1
        if(q > n) return 0;
        int posVal = findVal(1, 1, n, q);
        if(posVal <= 0) return 0;
        int r = rightMost(1, 1, n, posVal);
        int l = rightMost(1, 1, n, posVal+1);
        int rem = q - l;
        if(l >= 1)          update(1, 1, n, 1, l, -1);
        if(r-rem+1 <= r)    update(1, 1, n, r-rem+1, r, -1);
        return 1;
}};
    

bool cmp(int l, int r) {
    return l > r;
}

SortedST ST;

int val[MAX], q[MAX];

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    
    
    for(int i = 0; i < m; ++i)
        scanf("%d", &q[i]);
    
    sort(val+1, val+n+1, cmp);
    ST.init(1, 1, n, val);
    
    //SegPrint(1, 1, n);
    
    
    // Query Begins
    for(int i = 0; i < m; ++i) {
        if(!ST.MinusQuery(q[i], n)) {
            m = i;
            break;
        }
    }
    
    printf("%d\n", m);
    return 0;
}

/*
5 5
1 3 3 4 5
1 2 4 4 4

5 6
1 3 3 4 5
1 2 2 4 4 1

3 3
2 2 2
2 2 1 1
*/
