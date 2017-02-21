//LightOJ
//1133 - Array Simulation
#include<bits/stdc++.h>
using namespace std;

int a[110], n;

int main()
{
    int t, x, y, q;
    char c;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("Case %d:\n", Case);
        while(q--) {
            scanf(" %c", &c);
            if(c == 'S') {
                scanf(" %d", &x);
                for(int i = 0; i < n; i++)
                    a[i] += x;
            }
            else if(c == 'M') {
                scanf(" %d", &x);
                for(int i = 0; i < n; i++)
                    a[i] *= x;
            }
            else if(c == 'D') {
                scanf(" %d", &x);
                for(int i = 0; i < n; i++)
                    a[i] /= x;
            }
            else if(c == 'R')
                reverse(a, a+n);
            else {
                scanf(" %d %d", &x, &y);
                swap(a[x], a[y]);
            }
        }
        printf("%d", a[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", a[i]);
        printf("\n");
    }
    return 0;
}
