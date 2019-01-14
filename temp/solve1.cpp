// LightOJ
// 1267 - Points in Rectangle (II)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    ll tree[200100], MaxVal;
    void init(int sz=1e7) {
        memset(tree, 0, sizeof tree);
        MaxVal = sz+1;
    }
    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    ll read(int idx) {
        if(idx <= 0) return 0;
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx];
        return sum;
    }
    ll read(int l, int r) {
        if(l > r) swap(l, r);
        ll ret = read(r) - read(l-1);
        return ret;
}};


struct point {
    int x, y, x1, y1, x2, y2, q, idx;

    point(int xx, int yy, int qq = 0, int xx1 = 0, int yy1 = 0, int xx2 = 0, int yy2 = 0, int iidx = 0) {
        x = xx, y = yy, q = qq;
        x1 = xx1, y1 = yy1, x2 = xx2, y2 = yy2;
        idx = iidx;
}};

/*
q =     0 : starting point query
        1 : cartesian points
        2 : end point query
*/

bool cmp(point &a, point &b) {
    if(a.x != b.x)
        return a.x < b.x;
    if(a.y != b.y)
        return a.y < b.y;
    return a.q < b.q;
}

ll ans[200100];
vector<point>p;
BIT F;
map<ll, ll>COMP;

int main() {
    ll t, n, q, x1, x2, y1, y2;
    scanf("%lld", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld", &n, &q);

        p.clear();
        COMP.clear();

        for(int i = 0; i < n; ++i) {
            scanf("%lld%lld", &x1, &y1);
            p.push_back({x1, y1, 1});
            COMP[y1];
        }

        for(int i = 0; i < q; ++i) {
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            p.push_back({x1, y1, 0, x1, y1, x2, y2, i});
            p.push_back({x2, y2, 2, x1, y1, x2, y2, i});
            COMP[y1], COMP[y2];
        }

        ll id = 0;
        for(auto it = COMP.begin(); it != COMP.end(); ++it)
            it->second = ++id;

        for(auto it = p.begin(); it != p.end(); ++it) {
            it->y = COMP[it->y];
            if(it->q != 1)
                it->y1 = COMP[it->y1], it->y2 = COMP[it->y2];
        }

        sort(p.begin(), p.end(), cmp);
        F.init(id+10);
        memset(ans, 0, sizeof ans);

        for(auto it = p.begin(); it != p.end(); ++it) {
            if(it->q == 0)                          // start querty point
                ans[it->idx] = F.read(it->y2, it->y1);
            else if(it->q == 2)                     // end query point
                ans[it->idx] = F.read(it->y2, it->y1) - ans[it->idx];
            else                                    // point
                F.update(it->y, 1);
        }

        printf("Case %d:\n", Case);
        for(int i = 0; i < q; ++i)
            printf("%lld\n", ans[i]);
    }

    return 0;
}