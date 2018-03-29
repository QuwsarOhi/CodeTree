// Codeforces
// http://codeforces.com/contest/86/problem/D
// Powerful array

// MO's Algo

#include <bits/stdc++.h>
#define MAX 210000
using namespace std;
typedef long long ll;

struct query {
    int l, r, id;
};

const int block = 447;
query q[MAX];
int v[MAX], Count[2010000];
ll ansId[MAX], ans = 0;

bool cmp(query a, query b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}


void add(int x) {
    long long k = Count[v[x]]++;
    ans -= k*k*v[x];
    ans += (k+1)*(k+1)*v[x];
}


void remove(int x) {
    long long k = Count[v[x]]--;
    ans -= k*k*v[x];
    ans += (k-1)*(k-1)*v[x];
}


int main() {
    int n, Q;
    
    scanf("%d%d", &n, &Q);
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    
    
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
        
        ansId[q[i].id] = ans;
    }
    
    
    for(int i = 0; i < Q; ++i)
        printf("%lld\n", ansId[i]);
    
    return 0;
}
