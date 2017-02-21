//UVa
//1433 - Minimum Arc Distance
#include<bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int Ox, Oy, Ax, Ay, Bx, By, t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d %d %d %d %d", &Ox, &Oy, &Ax, &Ay, &Bx, &By);
        double R = sqrt((Ox-Ax)*(Ox-Ax) + (Oy-Ay)*(Oy-Ay));
        double AB = sqrt((Ax-Bx)*(Ax-Bx) + (Ay-By)*(Ay-By));
        double theta = acos((2*R*R - AB*AB)/(2*R*R));
        double ans = (2*PI*R * theta)/(2*PI);
        //printf("R : %f\n", R);
        //printf("AB : %f\n", AB);
        //printf("Theta : %f\n", theta);
        //printf("2*PI*R = %f\n", 2*PI*R);
        printf("Case %d: %f\n", Case, ans);
    }
    return 0;
}
