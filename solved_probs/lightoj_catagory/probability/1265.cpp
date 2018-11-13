// LightOJ
// 1265 - Island of Survival
// Probability / Expected Value

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tc, t, d;
    scanf("%d", &tc);
 
    for(int Case = 1; Case <= tc; ++Case) {
        scanf("%d%d", &t, &d);
        printf("Case %d: %.6lf\n", Case, t==0?1:(t&1?0:1.0/(t+1)));
    }
 
    return 0;
}