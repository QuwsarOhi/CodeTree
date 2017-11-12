// LightOJ
// 1038 - Race to 1 Again 

#include <bits/stdc++.h>
using namespace std;

int Div[1000010];
double E[1000010];

void countDiv(int n) {
    for(int i = 1; i <= n; ++i)
        Div[i] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = i; j <= n; j += i)
            ++Div[j];
    }
}

void calEx(int n) {
    E[1] = 0;
    for(int i = 2; i <= n; ++i) {
        int tmp = sqrt(i), cnt = 0;
        double Ex = 0;
        for(int j = 2; j <= tmp; ++j) {
            if(i%j == 0) {
                Ex += (1+E[j]);
                ++cnt;
                if(i/j != j) {
                    Ex += (1+E[i/j]);
                    ++cnt;
                }
            }
        }
        E[i] = (Ex+2)/(cnt+1);
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    calEx(100000);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        printf("Case %d: %.6lf\n", Case, E[n]);
    }
    return 0;
}
