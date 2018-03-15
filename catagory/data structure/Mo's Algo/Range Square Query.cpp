// TOPH
// Is It A Square?

// MO's Algo
// Complexity : Q*sqrt(N)

#include <stdio.h>
#include <bitset>
#include <math.h>
#include <algorithm>

#define MAX 100010
using namespace std;

struct query {
    int l, r, id;
};

bitset<MAX>countSqr, ans;
const int block = 320;
query q[MAX];
int val[MAX], sign = 1, zero = 0;


bool cmp(query &a, query &b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}

bool isSquare(int n) {
    if(n < 0)
        n *= -1;
    int t = sqrt(n);
    return (t*t == n);
}

void add(int x) {
    if(isSquare(val[x])) {
        if(val[x] == 0) ++zero;
        if(val[x] < 0) sign *= -1;
        return;
    }
    
    if(val[x] > 0)
        countSqr[val[x]].flip();
    else {
        countSqr[val[x]*-1].flip();
        sign *= -1;
    }
}

void remove(int x) {
    if(isSquare(val[x])) {
        if(val[x] == 0) --zero;
        if(val[x] < 0) sign *= -1;
        return;
    }
    
    if(val[x] > 0)
        countSqr[val[x]].flip();
    else {
        countSqr[val[x]*-1].flip();
        sign *= -1;
    }
}


int main() {
    int n, Q;
    countSqr.reset();
    
    scanf("%d%d", &n, &Q);
    for(int i = 0; i < n; ++i)
        scanf("%d", &val[i]);
    

    for(int i = 0; i < Q; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].l--, q[i].r--;
        q[i].id = i;
    }
    
    sort(q, q+Q, cmp);
    
    int l = 0, r = -1;
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        ans[q[i].id] = ((countSqr.count() == 0 && sign == 1) || zero > 0);
    }
    
    for(int i = 0; i < Q; ++i)
        printf("%s\n", ans[i] ? "Yes":"No");
    
    return 0;
}
