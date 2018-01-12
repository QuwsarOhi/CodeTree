#include <bits/stdc++.h>
using namespace std;

/*
 * 0 0 : Stuck
 * 0 1 : Stuck        // 0^0 = undefined according to problem setter
 * 0 2 : Stuck
 * 1 0 : Stuck
 * 1 1 : Stuck
 * 1 12 : Stuck
 * 12 0: Stuck
 * 12 1: 0
 * 1 12: Stuck
 * 0 12: Stuck
 */

int main() {
    //freopen("in.txt", "r", stdin);
    double a, x;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf %lf", &a, &x);
        if(a == 0 || a == 1 || x == 0)
            printf("Stuck\n");
        else
            printf("%.4lf\n", log(x)/log(a));
    }
    return 0;
}
