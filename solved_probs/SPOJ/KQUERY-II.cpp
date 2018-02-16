// SPOJ KQUERY-II

// IDEA : Fenwick Tree + Square Root Decomposition

// Array size n is 30000, where sqrt(n) = 174
// So we will convert n to sqrt(n) blocks (for some position range [block 2*block] ), each block will contain its own fenwick tree of index 1 to 10000
// Memomry Complexity becomes : 174*10000 which is considerable

// To be noted, BlockSize, is changed to due to time limit

// In each block(according to index) we will update 1 to the position of the value
// Removing the value is almost the same
// Query also works like Sqrt Decomposition


#include <bits/stdc++.h>
using namespace std;


int tree[380][10010], val[30100], BlockSize, MaxVal;

void update(int block, int idx, int val) {
    for( ; idx <= MaxVal; idx += idx & -idx)
        tree[block][idx] += val;
}


long long read(int block, int idx) {
    long long sum = 0;
    for( ; idx >= 1; idx -= idx & -idx)
        sum += tree[block][idx];
    return sum;
}


void Build(int n) {
    //BlockSize = sqrt(n);
    BlockSize = 340;
    
    for(int i = 1; i <= n; ++i)
        update(i/BlockSize, val[i], 1);
}


void Remove(int pos, int val) {
    update(pos/BlockSize, val, -1);
}

void Insert(int pos, int val) {
    update(pos/BlockSize, val, 1);
}


int Query(int l, int r, int k) {                // Query in range l -- r for k
    int Count = 0;
    while(l%BlockSize != 0 && l < r) {          // if l partially lies inside of a sqrt segment
        Count += val[l] > k;
        ++l;
    }
    while(l+BlockSize <= r) {                   // for all full sqrt segment
        Count += read(l/BlockSize, MaxVal) - read(l/BlockSize, k);
        l += BlockSize;
    }
    while(l <= r) {                             // for the rightmost partial sqrt segment values
        Count += val[l] > k;
        ++l;
    }
    
    return Count;
}

int main() {
    int n, l, r, k, q, x, t, pos;
    MaxVal = -1;
    
    scanf("%d", &n);
    
    
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &val[i]);
        MaxVal = max(val[i], MaxVal);
    }
    
    Build(n);
    scanf("%d", &q);
    
    while(q--) {
        scanf("%d", &t);
        
        if(t == 0) {
            scanf("%d%d", &pos, &x);
            Remove(pos, val[pos]);
            Insert(pos, x);
            val[pos] = x;
        }
        else {
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", Query(l, r, k));
        }
    }
    
    return 0;
} 
