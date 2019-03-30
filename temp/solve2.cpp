#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans[1000009];
vector<pair<ll, ll> >v;
map<ll, ll>com;

int tree[1000009], MaxVal;

void update(int idx, int val) {
    for( ; idx <= MaxVal; idx += idx & -idx)
        tree[idx] += val;
}

int read(int idx) {
    int sum = 0;
    for( ; idx > 0; idx -= idx & -idx)
        sum += tree[idx];
    return sum;
}

int checkBigger(int val) {
    return read(MaxVal) - read(val-1);
}


int main() {
    int t, n;
    ll x, y;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            scanf("%lld%lld", &x, &y);
            v.push_back({y, x});
            com[x];
        }

        sort(v.begin(), v.end());
        int tag = 1;
        for(auto it : com)
            com[it.first] = tag++;
        MaxVal = tag;
        memset(tree, 0, sizeof tree);
        //cerr << "MaxVal " << MaxVal << endl;

        printf("Case %d:", Case);

        int pos = 0;
        for(auto it : v) {
            int big = it.first;
            int val = com[it.second];

            //cerr << it.second << " :: " << it.first << " " << checkBigger(val) << " " << val << endl;

            if(checkBigger(val) == big) {
                //cerr << "INSERTING " << val << endl;
                ans[pos++] = it.second, update(val, 1);
                //cerr << "TOT " << read(MaxVal) << endl;
            }
            else {
                printf(" No ordering possible!\n");
                goto pass;
            }
        }

        for(int i = 0; i < n; ++i)
            printf(" %lld", ans[i]);
        printf("\n");
        pass:;
        v.clear(), com.clear();
    }

    return 0;
}