//UVa
//11157 - Dynamic Frog
//Greedy
#include<bits/stdc++.h>
using namespace std;

struct {
    int d;
    bool small, usable;
}v[110];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int t, mx, pos, x, n, d;
    char c, dash;
    scanf("%d", &t);
    for(register int Case = 1; Case <= t; Case++) {
        scanf("%d %d", &n, &d);
        for(register int i = 0 ; i < n; i++) {
            scanf(" %c %c %d", &c, &dash, &x);
            v[i].d = x;
            v[i].usable = 1;
            if(c == 'B')
                v[i].small = 0;
            else
                v[i].small = 1;
        }
        mx = 0, pos = 0;
        bool isBig = 0, skip = 0;
        for(register int i = 0; i < n; i++) {
            if(skip) {
                skip = 0;
                continue;
            }
            if(v[i].usable) {
                if(v[i].small && i+1 < n && !skip)
                    if(v[i+1].small) {
                        skip = 1;
                    }
                mx = max(mx, v[i].d-pos);
                pos = v[i].d;
                if(v[i].small)
                    v[i].usable = 0;
            }
        }
        mx = max(mx, d-pos);
        pos = 0;
        for(register int i = n-1; i >= 0; i--)
            if(v[i].usable) {
                mx = max(mx, (d- v[i].d)-pos);
                pos = d-v[i].d;
            }
        mx = max(mx, d-pos);
        printf("Case %d: %d\n", Case, mx);
    }
    return 0;
}
