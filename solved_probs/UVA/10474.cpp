//UVa
//10474 - Where is the Marble?
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int t = 1, n, q, x, pos;
    vector<int>v;
    while(scanf("%d %d", &n, &q) && (n || q)) {
        printf("CASE# %d:\n", t++);
        for(register int i = 0; i < n; i++) {
            scanf("%d", &x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        /*for(auto p : v)
            printf("%d ", p);
        printf("\n");*/
        while(q--) {
            scanf("%d", &x);
            vector<int> :: iterator it;
            it = lower_bound(v.begin(), v.end(), x);
            pos = it - v.begin();
            if(v[pos] == x)
                printf("%d found at %d\n", x, pos+1);
            else
                printf("%d not found\n", x);
        }
        v.clear();
    }
    return 0;
}
