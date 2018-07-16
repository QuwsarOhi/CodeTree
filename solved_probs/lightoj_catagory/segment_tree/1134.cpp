// LightOJ
// 1134 - Be Efficient

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 300002;


// Merge Sort Tree
struct MergeSortTree {
    vector<int>tree[MAX];

    void init(int pos, int l, int r, int val[]) {
        tree[pos].clear();
        if(l == r) {
            tree[pos].push_back(val[l]);
            return;
        }
    
        int mid = (l+r)>>1;
        init(pos<<1, l, mid, val);
        init(pos<<1|1, mid+1, r, val);
        merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
    }

    ll query(int pos, int l, int r, int L, int R, int k) {
        if(r < L || R < l)
            return 0;
    
        if(L <= l && r <= R)
            return (ll)(upper_bound(tree[pos].begin(), tree[pos].end(), k) - lower_bound(tree[pos].begin(), tree[pos].end(), k));
        
        int mid = (l+r)>>1;
        return query(pos<<1, l, mid, L, R, k) + query(pos<<1|1, mid+1, r, L, R, k);
}};

MergeSortTree MS;
int v[100010];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n, m;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &m);
        
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &v[i]);
            ans += (v[i]%m == 0); 
            v[i] += v[i-1];
            v[i] %= m;
        }
        
        MS.init(1, 1, n, v);
        for(int i = 1; i <= n; ++i)
            ans += MS.query(1, 1, n, i+1, n, v[i-1]);
        
        printf("Case %d: %lld\n", Case, ans);
    }
    
    return 0;
}
