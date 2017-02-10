//UVa
//10656 - Maximum Sum (II)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int x, n;
    bool first;
    while(scanf("%d", &n) && n) {
        first = 0;
        for(register int i = 0; i < n; i++) {
            scanf(" %d", &x);
            if(x && first)
                printf(" %d", x);
            else if(x && !first) {
                printf("%d", x);
                first = 1;
            }
        }
        if(first)
            printf("\n");
        else
            printf("0\n");
    }
    return 0;
}
