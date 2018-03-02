// CS Academy
// Candles
// https://csacademy.com/contest/archive/task/candles/statement/

// Observations:
// We need a data structure that will be sorted even after we decrease/increase some value in range
// if we build a segment tree with decreasing values and decrease values in a technique such that, the values in segment tree remains sorted

// first of all, it is needed to observed that in a descending valued segment tree, decreasing X values by 1 is only possible when
// the X'th index of the segment tree is non-zero

// so, for each query, we search for the X'th indexs' value, let the segment tree contains VAL in X'th index
// then we find two boundary the rightmost index where the value of the index element is same as VAL, let this index be r
// we also search for a rightmost index where the tree contains value VAL+1, let this index be l

// l tells us that we have 1 - l elements which's value is greater than zero
// we decrease values in range [1, l] and it is sure that the query is equal or greater than this range ( Why this happens?? )
// then we check if there is more candles to decrease, if so, we decrease from range [r-number_of_candels_still_needed_to_decrease+1, r] and it is
// guranteed that the rest of the candles are in this range and doesn't overlap with l  ( Why?? )


#include <bits/stdc++.h>
#define MAX 110000
using namespace std;

struct node {
    int val, prop;
};

node tree[5*MAX];
int val[MAX], q[MAX];

void init(int pos, int l, int r) {
    if(l == r) {
        tree[pos].val = val[l];
        tree[pos].prop = 0;
        return;
    }
    
    int mid = (l+r)>>1;
    
    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);
    
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

int findVal(int pos, int l, int r, int idx) {
    if(l == r)
        return tree[pos].val;
    
    propagate(pos, l, r);    
    int mid = (l+r)>>1;
    
    if(idx <= mid)
        return findVal(pos<<1, l, mid, idx);
    else
        return findVal(pos<<1|1, mid+1, r, idx);
}

void SegPrint(int pos, int l, int r) {
    if(l == r) {
        printf("pos %d : %d : %d, %d\n", pos, l, tree[pos].val, tree[pos].prop);
        return;
    }
    
    propagate(pos, l, r);
    int mid = (l+r)>>1;
    
    SegPrint(pos<<1, l, mid);
    SegPrint(pos<<1|1, mid+1, r);
}

void update(int pos, int l, int r, int L, int R, int val) {
    if(r < L || R < l)
        return;
    
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

int rightMost(int pos, int l, int r, int val) {
    if(l == r)
        return l;
    
    if(tree[pos].val < val)
        return 0;
        
    propagate(pos, l, r);
    int mid = (l+r)>>1;
    
    if(tree[pos<<1|1].val >= val)
        return rightMost(pos<<1|1, mid+1, r, val);
    return rightMost(pos<<1, l, mid, val);
}
    
    

bool cmp(int l, int r) {
    return l > r;
}

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    
    
    for(int i = 0; i < m; ++i)
        scanf("%d", &q[i]);
    
    sort(val+1, val+n+1, cmp);
    init(1, 1, n);
    
    //SegPrint(1, 1, n);
    
    
    // Query Begins
    for(int i = 0; i < m; ++i) {
        if(q[i] > n) {
            printf("%d\n", i);
            return 0;
        }
        
        int posVal = findVal(1, 1, n, q[i]);
        //printf("Query : %d\n", q[i]);
        
        if(posVal <= 0) {
            //SegPrint(1, 1, n);
            printf("%d\n", i);
            return 0;
        }
        
        //printf("posVal : %d\n", posVal);
        //SegPrint(1, 1, n);
        
        int r = rightMost(1, 1, n, posVal);
        int l = rightMost(1, 1, n, posVal+1);
        int rem = q[i] - l;
        
        //printf("l : %d, r : %d, rem : %d\n", l, r, rem);
        
        //printf("Boundary1 : [%d, %d]\n", 1, l);
        //printf("Boundary2 : [%d, %d]\n", r-rem+1, r);
        
        if(l >= 1)
            update(1, 1, n, 1, l, -1);
        if(r-rem+1 <= r)
            update(1, 1, n, r-rem+1, r, -1);
        
        //printf("\n--------------------\n");
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
