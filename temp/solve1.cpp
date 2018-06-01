// LightOJ
// 1062 - Crossed Ladders

#include <bits/stdc++.h>
#define EPS 1e-8
using namespace std;

double x, y, c;

double getHeight(double base) {
    double x0 = sqrt(x*x - base*base);
    double y0 = sqrt(y*y - base*base);
    return (x0*y0) / (x0+y0);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lf%lf%lf", &x, &y, &c);
        
        double lo = 0, hi = min(x, y), mid, h;
        for(int i = 0; i < 150; ++i) {
            mid = (lo+hi)/2;
            
            h = getHeight(mid);
            
            if(c - h >= EPS)
                hi = mid;
            else
                lo = mid;
        }

        printf("Case %d: %.6lf\n", Case, mid);
    }
    return 0;
}
