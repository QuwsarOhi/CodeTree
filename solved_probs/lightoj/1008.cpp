//LightOJ
//1008 	Fibsieve`s Fantabulous Birthday
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    long long n, p1, p2, upper_left, lower_right, mid;
    int t;
    scanf("%d", &t);
    for(register int Case = 1; Case <= t; Case++) {
        scanf("%lld", &n);
        p1 = ceil(sqrt(n));
        upper_left = p1*p1;
        lower_right = upper_left - p1 - p1 + 2;
        if(!(p1 & 1))       //p1 is even
            swap(upper_left, lower_right);
        mid = (upper_left + lower_right) / 2;
        if(n == mid)
            p2 = p1;
        else if(!(p1 & 1)) {       //if p1 is even
            if(n > mid)
                p2 = p1 - (n - mid);
            else {
                p2 = p1;
                p1 = p1 - (mid - n);
            }
        }
        else {
            if(n < mid)
                p2 = p1 - (mid - n);
            else {
                p2 = p1;
                p1 = p1 - (n - mid);
            }
        }
        //printf("upper_left : %lld, lower_right : %lld mid : %lld\n", upper_left, lower_right, mid);
        printf("Case %d: %lld %lld\n", Case, p1, p2);
    }
    return 0;
}
