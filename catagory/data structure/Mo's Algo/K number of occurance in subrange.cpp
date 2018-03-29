// Codeforces
// http://codeforces.com/problemset/problem/220/B

// MO's Algorithm

#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

struct query {
    int l, r, id;
}q[MAX];

const int block = 320;
int v[MAX], ans[MAX], Ans = 0;
unordered_map<int, int>Map;

bool cmp(query a, query b) {
    int query_a = a.l/block, query_b = b.l/block;
    if(query_a == query_b)
        return a.r < b.r;
    return query_a < query_b;
}

void add(int x) {
    int val = v[x];
    int tmp = ++Map[val];
    if(tmp == val)
        Ans++;
    else if(tmp-1 == val)
        --Ans;
}

void remove(int x) {
    int val = v[x];
    int tmp = --Map[val];
    if(tmp+1 == val)
        Ans--;
    if(tmp == val)
        Ans++;
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
        
        ans[q[i].id] = Ans;
    }
    
    for(int i = 0; i < Q; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}
