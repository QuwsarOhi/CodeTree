// UVa
// 1121 - Subsequence

#include <bits/stdc++.h>
#define MOD 998244353
#define MAX 100100
#define dd(XX)       cerr << #XX << " :: " << XX << endl;
using namespace std;
typedef long long ll;

ll v[MAX];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    ll n, s;

    while(scanf("%lld%lld", &n, &s) == 2) {
        for(int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);

        int l = 0, r = 0, ans = MAX;
        ll sum = v[0];

        while(r < n) {
            //cerr << l << " " << r << " " << sum << endl;

            while(l+1 <= r and sum > s)
                sum -= v[l++];

            while(l-1 >= 0 and sum < s)
                sum += v[--l];

            if(sum >= s) ans = min(ans, r-l+1);

            //cerr << "ADJ " << l << " " << r << " " << sum << endl;

            sum += v[++r];
        }

        printf("%d\n", ans == MAX ? 0:ans);
    }

    return 0;
}