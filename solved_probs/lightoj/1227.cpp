//LightOJ
//1227 - Boiled Eggs
#include<bits/stdc++.h>
using namespace std;

int main()
{
    register int t, n, p, q, sum, cnt, x;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d %d", &n, &p, &q);
        sum = cnt = 0;
        printf("Case %d: ", Case);
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            if(sum + x <= q) {
                sum+=x;
                cnt++;
            }
        }
        if(cnt > p)
            printf("%d\n", p);
        else
            printf("%d\n", cnt);
    }
    return 0;
}
