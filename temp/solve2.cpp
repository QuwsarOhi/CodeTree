#include <bits/stdc++.h>
using namespace std;

set<int>Set[100002];
bitset<100002>isPresent;

int main() {
    freopen("in", "r", stdin);

    int n, t, x, q, l, r;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d %d", &n, &q);
        isPresent.reset();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            Set[x].insert(i);
            isPresent[x] = 1;
        }
    
        while(q--) {
            scanf("%d %d %d", &l, &r, &x);
            if(isPresent[x]) {
                auto it = (Set[x].upper_bound(r));
                if(it != Set[x].begin())
                    it--;
                else
                    it = Set[x].end();
                    
                if(l <= *it && *it <= r)
                    printf("%d\n", *it);
                else
                    printf("-1\n");
            }
            else
                printf("-1\n");
        }
        
        for(int i = 0; i <= 100000; ++i)
            Set[i].clear();
    }
        
    return 0;
}