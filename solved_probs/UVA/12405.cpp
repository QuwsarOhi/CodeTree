//UVa
//12405 - Scarecrow
//greedy - coverage interval
#include<bits/stdc++.h>
using namespace std;

int n, t;
char c[110];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    scanf("%d", &t);
    for(register int ca = 1; ca <= t; ca++) {
        scanf(" %d", &n);
        for(register int i = 0; i < n; i++)
            scanf(" %c", &c[i]);
        c[n] = 0;
        int cnt = 0;
        for(register int i = 0; i <= n; i++)
            if(c[i] == '.') {
                cnt++;
                //printf("putting in %d\n", i+1);
                if(i+2 <= n) i+=2;
                else if(i+1 <= n) i++;
            }
        printf("Case %d: %d\n", ca, cnt);
    }
    return 0;
}
