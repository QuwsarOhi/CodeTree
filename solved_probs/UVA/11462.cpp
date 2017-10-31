// UVa
// 11462 - Age Sort

#include <bits/stdc++.h>
using namespace std;


int main() {
    int v[110] = {0}, n, x;
    while(scanf("%d", &n) && n != 0) {

        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            ++v[x];
        }
        bool first = 1;
        for(int i = 0; i <= 100; ++i)
            while(v[i] > 0) {
                if(first) {
                    printf("%d", i);
                    first = 0;
                }
                else
                    printf(" %d", i);
                --v[i];
            }
        printf("\n");
    }
    return 0;
}
