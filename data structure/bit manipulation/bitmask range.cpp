#include<bits/stdc++.h>
using namespace std;

void bitprint(int n, int len = 32)
{
    for(register int i = len - 1; i >= 0; i--) {
        if(n & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main()
{
    register int N, L, U, ith_bit, ans, i;
    while(scanf("%d %d %d", &N, &L, &U) != EOF) {
        ans = 0;
        printf("L : "), bitprint(L);
        printf("U : "), bitprint(U);
        printf("N : "), bitprint(N);
        for(i = 31 ; !(N & (1 << i)); i--);
        for( ; i >= 0; i--) {
            ith_bit = N & (1 << i);
            printf("%dth bit : ", i);
            if(N & (1 << i)) {
                printf("ON\n");
                int tmp = ans | (1 << i);
                if(tmp >= L && tmp <= U)
                    ans = tmp;
                else
                    continue;
            }
            else {
                printf("OFF\n");
                if((ans | (1 << i)) <= U)
                    ans |= (1 << i);
            }
            printf("ans : "), bitprint(ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
