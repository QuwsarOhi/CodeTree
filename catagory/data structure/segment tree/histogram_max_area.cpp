// LightOJ
// 1083 - Histogram 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll v[30010];
int tree[120000];

void init(int l, int r, int pos) {
    if(l == r) {
        tree[pos] = r;
        return;
    }
    int mid = (l+r)>>1;
    init(l, mid, pos<<1);
    init(mid+1, r, pos<<1|1);
    if(v[tree[pos<<1]] < v[tree[pos<<1|1]])
        tree[pos] = tree[pos<<1];
    else
        tree[pos] = tree[pos<<1|1];
}

int RangeMinQuery(int l, int r, int x, int y, int pos) {
    if(x > r || y < l)
        return -1;
    if(x <= l && r <= y)
        return tree[pos];
    int mid = (l+r)>>1;
    int lseg = RangeMinQuery(l, mid, x, y, pos<<1);
    int rseg = RangeMinQuery(mid+1, r, x, y, pos<<1|1);
    //cout << "mid : " << mid << " " << lseg << " " << rseg << endl;
    if(lseg == -1)
        return rseg;
    else if(rseg == -1)
        return lseg;
    else
        return (v[lseg] < v[rseg]) ? lseg : rseg;
}

ll DivideConquer(int l, int r, int n) {
    //cout << l << " -- " << r << endl;
    if(l > r)
        return -1e9;
    if(l == r)
        return v[l];
    int mid = RangeMinQuery(1, n, l, r, 1);
    //cout << "MID " << mid << endl;
    ll lQuery = DivideConquer(l, mid-1, n);
    ll rQuery = DivideConquer(mid+1, r, n);
    
    return max(lQuery, max(rQuery, v[mid]*(r-l+1)));
}
     

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%lld", &v[i]);
        init(1, n, 1);
        printf("Case %d: %lld\n", Case, DivideConquer(1, n, n));
    }
    return 0;
}
