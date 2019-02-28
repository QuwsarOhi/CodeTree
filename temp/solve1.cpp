#include <bits/stdc++.h>
#define dbug(x)     cerr << #x << " = " << x << endl
#define MAX 300010
using namespace std;
typedef long long ll;

ll v[MAX], seg[MAX];
int block;

void build(int n) {
    block = sqrt(n + .0) + 1;
    int l = 0, r = 0;
    for( ; r < n; ++r) {
        if(r%block == 0 and r != 0) {
            sort(seg+l, seg+r);
            cerr << l << " -- " << r << endl;
            l = r;
        }
        seg[r] = v[r];
    }
    cerr << l << " -- " << r << endl;
    sort(seg+l, seg+r);
}

void getRange(int idx, int n, int &l, int &r) {
    int segIndx = idx/block;
    l = segIndx*block;
    r = l+block-1;
}

void update(int idx, int n, ll val) {
    int l, r;
    getRange(idx, n, l, r);
    ++r;

    v[idx] = seg[idx] = val;
    cerr << "Update at " << idx << " val " << val << " " << l << " -- " << min(r, n) << endl;
    sort(seg+l, seg+min(r, n));
}

ll query(int ql, int qr, ll val) {
    ll ret = 0;
    cerr << "Query " << ql << " " << qr << " val " << val << endl;
    while(ql <= qr) {
        if(ql % block == 0 and ql + block - 1 <= qr) {
            int t = lower_bound(seg+ql, seg+ql+block, val) - seg;
            ret += t - ql;
            cerr << t - ql << endl;
            ql += block;
        }
        else
            ret += v[ql++] < val;
    }
    return ret;
}

void printer(int n) {
    cerr << "Block " << block <<  endl;
    for(int i = 0; i < n; ++i) {
        if(i > 0 and i%block == 0)
            cerr << endl;
        cerr << seg[i] << "(" << i << ") ";
    }
    cerr << endl;
}

int main() {
    ll n, m, u, l, r, vv, p;
    cin >> n >> m >> u;

    for(int i = 0; i < n; ++i) 
        cin >> v[i];
    build(n);

    while(m--) {
        cin >> l >> r >> vv >> p;
        --l, --r, --p;
        ll k = query(l, r, vv);
        update(p, n, (k*u)/(r-l+1));
    }

    //printer(n);

    for(int i = 0; i < n; ++i)
        cout << v[i] << "\n";

    return 0;
}

/*

10 1 11
1 6 8 3 7 5 2 9 10 4

10 1 11
1 1 1 1 1 1 1 1 1 1

10 1 11
10 10 10 10 10 10 10 10 10 10

*/