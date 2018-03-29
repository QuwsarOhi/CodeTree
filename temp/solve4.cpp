#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100000+7;
const int M = 1e9+7;

struct bit {
    LL a[N];
    int n;

    bit(int nn)   {n=nn; memset(a, 0, sizeof a);}

    void update(int idx, LL inc)
    {
        inc = (inc%M + M)%M;
        for (idx=idx; idx<=n; idx += idx & -idx)
            a[idx]=(a[idx] + inc)%M;
    }

    LL query (int idx)
    {
        LL sum = 0;
        for (idx=idx; idx>0; idx -= idx & -idx)
            sum = (sum + a[idx] + M)%M;
        return sum;
    }

    LL query (int l, int r)
    {
        return (query(r) - query(l-1) + M) % M;
    }

    void upd(int idx, LL val)
    {
        LL v = query(idx, idx)%M;
        update(idx, (val - v + M) %M);
    }
};


int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    bit sq(n), sum(n);

    for (int i=1; i<=n; i++)
    {
        LL x;
        cin>>x;
        sq.upd(i, (x*x)%M);
        sum.upd(i, x);
    }

    int q;
    cin>>q;

    for (int i=0; i<q; i++)
    {
        LL l, x, y;
        cin>>l>>x>>y;

        if (l==1) {
            sq.upd(x, (y*y)%M);
            sum.upd(x, y);
        }

        else {
            LL sm = sum.query(x, y);
            LL sqsm = sq.query(x, y);
            LL ans = (sm*sm)%M - sqsm;
            ans = (ans % M + M)%M;
            if (ans % 2) ans+=M;
            ans/=2;
            cout<<ans<<endl;
        }
    }
}
