//UVa
//12032 - The Monkey and the Oiled Bamboo
#include<bits/stdc++.h>
using namespace std;

int Case, lo, hi, ans, t, mid, n, a[100010], tmp;

bool is_factor(int k)
{
    for(register int i = 0; i < n; i++) {
        if(a[i] == k)
            k--;
        else if(a[i] > k)
            return 0;
    }
    return 1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    scanf("%d", &t);
    for(register int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        for(register int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(register int i = n-1; i > 0; i--)
            a[i] = a[i] - a[i-1];
        hi = 1e8;
        lo = 0;
        for(register int i = 0; i < 100; i++) {
            mid = (hi + lo)/2;
            if(is_factor(mid)) {
                ans = mid;
                hi = mid;
            }
            else
                lo = mid;
        }
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
