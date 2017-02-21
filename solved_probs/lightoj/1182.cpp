#include <bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, x;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d", &x);
        int cnt = __builtin_popcount(x);
        printf("Case %d: ", Case);
        if(cnt & 1)
            puts("odd");
        else
            puts("even");
    }
    return 0;
}
