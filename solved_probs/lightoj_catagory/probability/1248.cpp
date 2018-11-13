// LightOJ
// 1248 - Dice (III)
// Expected Value

#include <bits/stdc++.h>
using namespace std;

double S(int a, int b) {
    double r = a/(double)b;
    return r/(1 - r);
}

int main() {
    int t, n;
    scanf("%d", &t);

    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        double ans = n;

        for(int i = 1; i < n; ++i)
            ans += S(i, n);

        printf("Case %d: %.6f\n", Case, ans);
    }
    return 0;
}
