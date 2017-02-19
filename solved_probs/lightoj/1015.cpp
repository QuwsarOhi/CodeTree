//UVa
//1015 	Brush (I)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, sum, n;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d", &n);
        sum = 0;
        while(n--) {
            scanf("%d", &x);
            if(x >= 0)
                sum += x;
        }
        printf("Case %d: %d\n", Case, sum);
    }
    return 0;
}
