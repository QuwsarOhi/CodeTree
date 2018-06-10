// LightOJ
// 1088 - Points in Segments

#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int main() {
    int t, n, q, x, l, r;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &n, &q);
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v.push_back(x);
        }
        
        printf("Case %d:\n", Case);
        
        while(q--) {
            scanf("%d%d", &l, &r);
            printf("%d\n", int(upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l)));
        }
        v.clear();
    }
    return 0;
}
