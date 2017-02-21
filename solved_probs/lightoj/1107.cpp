//LightOJ
//1107 - How Cow
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t, q, x, y, x1, y1, x2, y2;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &q);
        printf("Case %d:\n", Case);
        while(q--) {
            scanf("%d %d", &x, &y);
            if(x <= x2 && x >= x1 && y <= y2 && y >= y1)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
