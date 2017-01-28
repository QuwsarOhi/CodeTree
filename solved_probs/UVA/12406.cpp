//UVa
//12406 Help Dexter
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int t, p, q, len, devider;
    register long long smallest, largest, num;
    scanf("%d", &t);
    for(int case_num = 1; case_num <= t; case_num++) {
        scanf("%d %d", &p, &q);
        len = 1 << p;
        devider = 1 << q;
        largest = smallest = -1;
        for(register int i = 0; i < len; i++) {
            num = 0;
            register long long n = 1;
            for(int j = 0; j < p; j++) {
                if(i & 1<<j)
                    num += 1*n;
                else
                    num += 2*n;
                n*=10;
            }
            //printf("%d\n", num);
            if(num % devider == 0) {
                if(largest == -1)
                    largest = num;
                else
                    smallest = num;
            }
        }
        if(smallest == -1 && largest == -1)
            printf("Case %d: impossible\n", case_num);
        else if(smallest == -1)
            printf("Case %d: %lld\n", case_num, largest);
        else
            printf("Case %d: %lld %lld\n", case_num, smallest, largest);
    }
    return 0;
}
