//UVa
//11054 - Wine trading in Gergovia
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, a[100009], tmp;
    while(scanf("%d", &n) && n) {
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                scanf("%d", &a[i]);
                continue;
            }
            scanf("%d", &a[i]);
            tmp = a[i-1];
            if(tmp < 0)
                tmp *= -1;
            sum += tmp;
            a[i] += a[i-1];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
