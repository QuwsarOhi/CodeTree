//UVa
//10341 - Solve It
//Bisection Method
#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int p, q, r, s, t, u;

double f(double x)
{
    return p * exp(-x) + q * sin(x) + r *cos(x) + s * tan(x) + t*x*x + u;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register double lo, hi, mid, ans;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        lo = 0;
        hi = 1;
        if(f(lo) * f(hi) > 0)
            printf("No solution\n");
        else {
            for(register int i = 0; i < 50; i++) {
                mid = (lo+hi)/2.0;
                if(f(mid) <= EPS) {         //as it returns double, for precision EPS is added instead of f(mid) == 0
                    ans = mid;
                    hi = mid;
                }
                else
                    lo = mid;
            }
            printf("%.4f\n", ans);
        }
    }
    return 0;
}
