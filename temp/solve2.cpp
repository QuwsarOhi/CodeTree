#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll v[402], n;

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> v[i];

    ll l, r, tl, tr, mn, ans = 0, cst;
    for(int i = 0; i < n-1; ++i) {
        mn = 10000000000000000;

        //cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << endl;

        for(l = 0; l < n-1; ++l) {
            if(v[l] != 0) {
                for(r = l+1; r < n and v[r] == 0; ++r);

                //cerr << l << " " << r << endl;
                // choose l, r
                if(r < n) {
                    cst = v[l] + v[r];
                    if(cst < mn)
                        mn = cst, tl = l, tr = r;
                }
            }
        }

        //cerr << "CHOOSE " << tl << " " << tr << " :: " << v[tl] << " + " << v[tr] << " = " << mn << endl;
        ans += mn;
        v[tl] = mn, v[tr] = 0;
    }

    cout << ans << endl;
    return 0;
}