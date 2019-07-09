#include <bits/stdc++.h>
#define INF 1e17
using namespace std;
typedef long long ll;

set<int>s;
ll a[100009];

pair<int, int> getLR(int v) {
    auto it = s.find(v);
    auto it2 = it;
    pair<int, int> ret;

    if(it == s.begin())
        ret.first = *(--s.end());
    else
        ret.first = *(--it2);
    it++;

    if(it == s.end())
        ret.second = *s.begin();
    else
        ret.second = *it;

    return ret;
}

priority_queue<tuple<ll, int, int> > pq;

int main() {
    int n, t;
    cin >> t;

    while(t--) {
        cin >> n;

        while(pq.size()) pq.pop();

        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        for(int i = 1; i+1 <= n; ++i)
            pq.push(make_tuple(-(a[i]+a[i+1]), i, i+1));
        pq.push(make_tuple(-(a[1]+a[n]), 1, n));

        s.clear();
        for(int i = 1; i <= n; ++i)
            s.insert(i);

        ll tot = 0;
        while(s.size() > 1) {
            ll sum = -get<0>(pq.top());
            int l = get<1>(pq.top());
            int r = get<2>(pq.top());
            int m = r;
            pq.pop();

            if(a[l] + a[r] != sum)
                continue;

            tot += sum;
            //cerr << "GOT " << l << " " << r << " : " << sum << ", " << tot << endl;
            s.erase(l);
            a[l] = 3*INF, a[r] = sum;
            pair<int, int> tmp = getLR(m);
            l = tmp.first, r = tmp.second;

            pq.push(make_tuple(-(a[l]+a[m]), l, m));
            pq.push(make_tuple(-(a[m]+a[r]), m, r));
        }

        cout << tot << endl;
    }

    return 0;
}


/*

1
6
57
89
65
57
51
30

*/