// SPOJ - GSS4 - Can you answer these queries IV
// http://www.spoj.com/problems/GSS4/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long tree[200000], val[200000], MaxVal;
set<ll>Set;
vector<ll>Add;

void update(ll idx, ll val) {
    for( ; idx <= MaxVal; idx += idx & -idx)
        tree[idx] += val;
}

long long read(ll idx) {
    long long sum = 0;
    for( ; idx > 0; idx -= idx & -idx)
        sum += tree[idx];
    return sum;
}

long long ReadRange(ll l, ll r) {
    return read(r) - read(l-1);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    ll n, q, l, r, t, Case = 1;
    bool first = 1;

    while(scanf("%lld", &n) == 1) {

        printf("Case #%lld:\n", Case++);
        MaxVal = n;
        memset(tree, 0, sizeof tree);
        Set.clear();
        Add.clear();

        for(ll i = 1; i <= n; ++i) {
            scanf("%lld", &val[i]);
            if(val[i] > 1)
                Set.insert(i);
            update(i, val[i]);
        }

        scanf("%lld", &q);

        while(q--) {
            scanf("%lld%lld%lld", &t, &l, &r);
            if(l > r)
                swap(l, r);
            if(t == 0) {
                auto low = Set.lower_bound(l), hi = Set.upper_bound(r);

                while(low != hi) {
                    ll pos = *low;
                    long long newVal = (long long)sqrt(val[pos]);

                    //prllf("pos %d, val %lld, newVal %lld, after Update %lld\n", pos, val[pos], newVal, -(val[pos]-newVal));

                    update(pos, -(val[pos]-newVal));
                    low = Set.erase(low);

                    if(newVal != sqrt(newVal))
                        Add.push_back(pos);
                    val[pos] = newVal;
                }

                for(auto it : Add)
                    Set.insert(it);
                Add.clear();
            }
            else {
                printf("%lld\n", ReadRange(l, r));
                //prllf("%d : %d, %d : %d\n", r, read(r), l, read(l));
            }
        }

        printf("\n");
    }
    return 0;
}

