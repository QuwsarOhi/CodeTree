// LightOJ
// 1383 - Underwater Snipers

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;


bool cmp(pll &x, pll y) {
    if(x.second != y.second)
        return x.second < y.second;
    return x.first < y.first;
}

vector<pll> interval, p;

bool Check(ll yy, ll d, ll s) {
    ll y1, cover;
    //cerr << "TRY " << yy << endl;

    for(int i= 0; i < p.size(); ++i) {
        y1 = p[i].second - yy;
        if(y1 > d) return 0;

        cover = sqrt(1.0*d*d - 1.0*y1*y1);
        interval[i].first = p[i].first - cover;
        interval[i].second= p[i].first + cover;
    }

    sort(interval.begin(), interval.end(), cmp);
    int cnt = 0, p;

    for(int i = 0; i < interval.size(); ) {
        p = interval[i++].second, ++cnt;
        if(cnt > s) return 0;
        while(i < interval.size() and interval[i].first <= p) ++i;
    }

    return cnt <= s;
}

ll BS(ll lo, ll hi, ll d, ll s) {
    ll mid, ans = hi+1;

    for(int i = 0; i < 60; ++i) {
        mid = (lo+hi)/2;

        if(Check(mid, d, s))
            hi = mid-1, ans = mid;
        else
            lo = mid+1;
    }

    return ans;
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    ll t, k, n, s, d;
    scanf("%lld", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lld%lld%lld%lld", &k, &n, &s, &d);

        p.resize(n), interval.resize(n);
        for(int i = 0; i < n; ++i)
            scanf("%lld%lld", &p[i].first, &p[i].second);

        sort(p.begin(), p.end());
        ll ans = BS(k-d-10, k, d, s);

        printf("Case %d: ", Case);

        if(ans > k)
            printf("impossible\n");
        else
            printf("%lld\n", k-ans);
    }

    return 0;
}