#include<bits/stdc++.h>
using namespace std;

int len(int n)
{
    int i = 31;
    for( ; i >= 0; i--)
        if((n & (1 << i)))
            break;
    return i+1;
}

int main()
{
    int t, x, ans, tmp, cnt;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d", &x);
        cnt = __builtin_popcount(x);
        tmp = (1 << len(x)+1);
        for(register int i = tmp; i > x; i--) {
            if(__builtin_popcount(i) == cnt)
                ans = i;
        }
        printf("Case %d: %d\n", Case, ans);
        //printf("%d iterations\n", itr);
    }
    return 0;
}
