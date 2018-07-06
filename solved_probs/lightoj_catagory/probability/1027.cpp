// LightOJ
// 1027 - A Dangerous Maze

// Ex = (Time[i] + Ex)/n +    (Time[i+1])/n    + ....    (Time[n] + Ex)/n
//            ^                         ^
//            |                         |
//  If again enters in maze     If leaves the maze

#include <bits/stdc++.h>
using namespace std;
     
int main() {
int n, b, t, sum, v, x;
       
scanf("%d", &t);
       
for(int Case = 1; Case <= t; ++Case) {
    scanf("%d", &n);
    sum = x = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &v);
            sum += abs(v);
            if(v < 0)
                ++x;
        }
           
        printf("Case %d: ", Case);
           
        if(n-x <= 0)
            printf("inf\n");
        else {
            b = (n-x);
            int t = __gcd(sum, b);
            //printf("%d %d\n", sum, b);
            sum /= t;
            b /= t;
            printf("%d/%d\n", sum, b);
        }
    }
       
    return 0;
}
     
