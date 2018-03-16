#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100100;

struct BIT {
    vector<ll>tree;
    int MaxVal;
    
    void init(int sz=1e7) {
        tree.resize(sz+1, 0);
        MaxVal = sz+1;
    }

    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }

    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx];
        return sum;
    }
    
    ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        return ret;
    }
    
    ll size() {
        return read(MaxVal);
    }
};

BIT t1;

struct query {
    int l, r, id;
} q[MAX];

bool cmp(query a, query b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}


void addLeft(int x) {
    int idx = Map[val[x]];
    int smaller = TOT - t1.read(idx+1);
    Ans += bigger;
    t1.update(idx, 1);
    ++TOT;
}


void removeLeft(int x) {
    int idx = Map[val[x]];
    int smaller = TOT - t1.read(idx+1);
    Ans -= bigger;
    t1.update(idx, -1);
    --TOT;
}


void addRight(int x) {
    int idx = Map[val[x]];
    int smaller = TOT - t1.read(idx);
    Ans += smaller;
    t1.update(idx, 1);
    ++TOT;
}

void removeRight(int x) {
    int idx = Map[val[x]];
    int smaller = TOT - t1.read(idx);
    Ans -= smaller;
    t1.update(idx, -1);
    --TOT;
}


int main() {
    int n, Q;
    
    scanf("%d%d", &n, &Q);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        Map[v[i]];
    }
    
    int LIM = 0;
    for(auto it = Map.begin(); it != Map.end(); ++it)
        it->second = ++LIM;
    
    t1.init(LIM+2);
    
    for(int i = 0; i < q; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].l--, q[i].r--;
        q[i].id = i;
    }
    
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    
    
}
