//UVa
//10365 - Blocks
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    register int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n == 4) { printf("16\n"); continue; }
        register int m = n*4 + 2, cnt=0, c = 0;
        for(register int i = 1; i < n-3; i++) {
            for(register int j = 1; j < n-2; j++) { if(i * j > n) continue;
                    int k = n/(i*j) + 0.0005;
                    int tmp = i * j * k;
                    cnt++;
                    if(tmp != n) continue;
                    int area = i*j*2 + i*k*2 + j*k*2;
                    m = min(area, m);
            }
        }
        printf("%d\n", m); //cnt, c);
    }
    return 0;
}
