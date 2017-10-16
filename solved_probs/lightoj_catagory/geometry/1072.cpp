// LightOJ
// 1072 - Calm Down 

#include <bits/stdc++.h>
#define PI acos(-1.0)
#define EPS 1e-9
using namespace std;
 
inline bool isEqual(double a, double b) {
    if(abs(a - b) <= EPS)
        return 1;
    return 0;
}
 
inline bool isGreater(double a, double b) {
    if(a >= b+EPS)
        return 1;
    return 0;
}
 
int n;
double R;
 
double BinarySearch(double lo, double hi) {
    double ans = -1, r;
   
    for(int i = 0; i < 200; ++i) {
        r = (lo+hi)/2;
        double a = R-r;
        double b = r+r;
        double theta = acos((2*a*a - b*b) / (2*a*a));
        //printf("ans : %lf, theta : %lf, 2PI : %lf : %lf :: %lf\n", ans, theta, 2*PI, theta*n, (2*a*a - b*b) / (2*a*a));
        if(isEqual(theta*n, 2*PI)) {
            ans = r;
            lo = r;
        }
        else if(isGreater(theta*n, 2*PI))
            hi = r;
        else
            lo = r;
    }
    return ans;
}
 
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
   
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%lf %d", &R, &n);
        printf("Case %d: %.6lf\n", Case, BinarySearch(0, R));
    }
    return 0;
}
