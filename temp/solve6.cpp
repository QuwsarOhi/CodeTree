#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int main() {
    int t, n, x, ans;
    vector<int> :: iterator it;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);

        v.clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j) {
                it = lower_bound(v.begin(), v.end(), v[i]+v[j]);
                if(it == v.end()) continue;

                int idx = (it - v.begin());
                ans += n-idx;
            }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}