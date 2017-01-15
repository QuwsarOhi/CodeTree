//UVa
//10125 - Sumsets
#include <bits/stdc++.h>
using namespace std;

long long a[1010];

int main()
{
    int n;
    while(scanf("%d", &n) && n) {
        bool found = 0;
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        sort(a, a+n);
        for(register int h = n-1; h >= 0 && !found; h--)
            for(register int i = 0; i < n - 2 && !found; i++)
                for(register int j = i+1; j < n - 1 && !found; j++)
                    for(register  int k = j+1; k < n && !found; k++) {
                        if((a[h] == a[i] + a[j] + a[k]) && (a[h]!= a[i]) && (a[h]!= a[j]) && (a[h]!=a[k])) {
                            printf("%lld\n", a[h]);
                            found = 1;}
                    }
        if(!found) printf("no solution\n");
    }
    return 0;
}
