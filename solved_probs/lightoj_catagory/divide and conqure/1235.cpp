// LightOJ
// 1235 - Coin Change (IV)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>s[2];
ll v[20];
int n;

void recur(int pos, ll sum, const int &lim, const int &idx) {
    if(pos == lim) {
        s[idx].push_back(sum);
        return;
    }

    recur(pos+1, sum, lim, idx);
    recur(pos+1, sum+v[pos], lim, idx);
    recur(pos+1, sum+v[pos]*2, lim, idx);
}

int main() {
    int t;
    ll k;
    cin >> t;

    for(int Case = 1; Case <= t; ++Case) {
        cin >> n >> k;

        for(int i = 0; i < n; ++i)
            cin >> v[i];


        s[0].clear();
        s[1].clear();

        recur(0, 0, n/2, 0);
        recur(n/2, 0, n, 1);

        sort(s[1].begin(), s[1].end());

        bool ok = 0;
        for(int i = 0; i < s[0].size() and not ok; ++i) {
            ll sub = k - s[0][i];
            if(sub == 0)
                ok = 1;
            if(sub > 0 and binary_search(s[1].begin(), s[1].end(), sub))
                ok = 1;
        }

        cout << "Case " << Case << ": " << (ok ? "Yes":"No") << "\n";
    }

    return 0;
}