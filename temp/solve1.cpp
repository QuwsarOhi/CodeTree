#include <bits/stdc++.h>
#define MAX 300100
using namespace std;
typedef long long ll;

int block;
ll val[MAX];
vector<ll>seg[MAX];

void built(int n) {
    block = sqrt(n + .0) + 1;
    
    for(int i = 0; i < n; ++i)
        seg[i/block].push_back(val[i]);
    
    int len = n/block + 1;
    for(int i = 0; i < len; ++i)
        sort(seg[i].begin(), seg[i].end());
}

void update(int idx, ll newVal) {
    int blockIdx = idx/block;
    ll pst = val[idx];
    for(int i = 0; i < seg[blockIdx].size(); ++i)
        if(seg[blockIdx][i] == pst) {
            seg[blockIdx][i] = newVal;
            break;
        }
    
    val[idx] = newVal;
    sort(seg[blockIdx].begin(), seg[blockIdx].end());
}

ll query(int l, int r, ll qval) {
    ll ret = 0;
    for(int i=l; i<=r; ) {
        if(i % block == 0 && i + block - 1 <= r) {
            int idx = i/block;
            ret += ll(lower_bound(seg[idx].begin(), seg[idx].end(), qval) - seg[idx].begin());
            i += block;
        }
        else {
            ret += val[i] < qval;
            ++i;
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, u, k, l, r, v, p, q;

    cin >> n >> q >> u;
    for(int i = 0; i < n; ++i)
        cin >> val[i];

    built(n);
    while(q--) {
        cin >> l >> r >> v >> p;
        k = query(--l, --r, v);
        update(--p, (u*k)/double(r-l+1));
    }

    for(int i = 0; i < n; ++i)
        cout << val[i] << "\n";

    return 0;
}
