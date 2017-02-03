//UVa
//11413 - Fill the Containers
#include<bits/stdc++.h>
using namespace std;

int a[1010];

bool can_be_used(int cap, int num_of_cont, int num_of_v)
{
    register int tmp = cap;
    for(register int i = 0; i < num_of_v; i++) {
        if(cap < a[i])
            return 0;
        if(tmp >= a[i])
            tmp -= a[i];
        else {
            tmp = cap - a[i];
            num_of_cont--;
        }
        if(num_of_cont < 0)
            return 0;
    }
    num_of_cont--;
    if(num_of_cont < 0)
        return 0;

    return 1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int n, c, lo, hi, mid, ans;
    while(scanf("%d %d", &n, &c) != EOF) {
        hi = 1e8;
        lo = 0;
        ans = 0;
        for(register int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            ans = max(ans, a[i]);
        }
        if(n != c) {
            for(register int i = 0; i < 100; i++) {
                mid = (hi + lo)/2;
                if(can_be_used(mid, c, n)) {
                    ans = mid;
                    hi = mid;
                }
                else
                    lo = mid;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
