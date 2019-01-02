// LightOJ
// 1307 - Counting Triangles

#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

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
                it = upper_bound(v.begin(), v.end(), v[i]+v[j]-1);
                if(it == v.end()) {
                    if(v[i]+v[j]-1 >= v.back()) {
                        --it;
                    }
                    else
                        continue;
                }
                if(*it >= v[i]+v[j]) --it;

                int idx = it - v.begin();
                int tot = (it - v.begin()) - j;

                if(v[i]+v[j] > v[idx] and v[i]+v[idx] > v[j] and v[j]+v[idx] > v[i])
                    ans += max(tot, 0);
            }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

