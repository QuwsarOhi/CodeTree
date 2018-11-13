// LightOJ
// 1317 - Throwing Balls into the Baskets
// Probability
 
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t, n, m, k;
    double p;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d%d%lf", &n, &m, &k, &p);
        int tot = n*k;
        printf("Case %d: %.6f\n", Case, p*tot);
    }
}
 