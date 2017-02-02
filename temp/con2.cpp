//UVa
//10718 - Bit Mask
#include<bits/stdc++.h>
using namespace std;

/*void bitprint(long long n, int len = 40)
{
    for(register int i = len - 1; i >= 0; i--) {
        if(n & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}*/

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long long N, L, U, tmp, ans, nth_bit, state, len;
    while(scanf("%lld %lld %lld", &N, &L, &U) != EOF) {
        ans = 0L;
        for(nth_bit = 31L ; nth_bit >= 0L; nth_bit--) {
            state = N & ((1L) << nth_bit);
            //printf("bit : %d\n", nth_bit);
            //if(state) printf("state : 1\n");
            //else printf("state : 0\n");
            if(state) {
                tmp = state - (1L);
                tmp |= ans;
                if(tmp < L) {
                    ans |= state;
                    //printf("Can't skip this 1, ans %d\n", ans);
                }
                //else
                    //printf("skipping this one temp %d\n", tmp);
            }
            else {
                tmp = ans | ((1L) << nth_bit);
                //bitprint(1L << nth_bit);
                //printf("ans : "), bitprint(ans);
                //printf("tmp : "), bitprint(tmp);
                //printf("tmp - > %lld\n", tmp);
                if(tmp <= U) {
                    //printf("temp %d is less than U\n", tmp);
                    ans = tmp;
                }
                //else
                    //printf("temp %d is bigger than U, skipping\n", tmp);
            }
            //printf("%d :: ", ans);
            //bitprint(ans, 10);
        }
        printf("%lld\n", ans);
        //bitprint(ans);
    }
    return 0;
}
