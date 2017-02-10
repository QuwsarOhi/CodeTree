//UVa
//11389 - The Bus Driver Problem
//Greedy - Load Balancing
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int m[110], e[110], n, d, r, hr;
    while(scanf("%d %d %d", &n, &d, &r) && (n || d || r)) {
        for(register int i = 0; i < n; i++)
            scanf("%d", &m[i]);
        for(register int i = 0; i < n; i++)
            scanf("%d", &e[i]);
        sort(m, m+n);
        sort(e, e+n, greater<int>());
        hr = 0;
        for(register int i = 0; i < n; i++) {
            int tmp = m[i] + e[i];
            if(tmp > d)
                hr += (tmp-d);
        }
        printf("%d\n", hr*r);
    }
    return 0;
}
