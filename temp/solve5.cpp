#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int t, n, m, a, b;
    scanf("%d", &t);
    vector<ll>v;
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        
        v.clear();
        for(int i = 0; i < n; ++i)
            v.push_back(1);
        for(int i = 0; i < m; ++i)
            v.push_back(0);
        
        ll sum = 0, ret = -1;
        do {
            sum = 0;
            for(auto it : v)
                sum = (sum<<1) + it;
            if(sum <= b and a <= sum) {
                ret = sum;
                break;
            }
        } while(prev_permutation(v.begin(), v.end()));
        
        printf("Case %d: %lld\n", Case, ret);
    }
    return 0;
}
