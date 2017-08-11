//UVa
//12210 - A Match Making Problem
//Greedy, Sorting
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int b, s, Case = 1, b_age[10010], s_age[10010], Min;
    while(scanf("%d %d", &b, &s) && (b || s)) {
        Min = 1e8;
        for(register int i = 0; i < b; i++) {
            scanf("%d", &b_age[i]);
            Min = min(b_age[i], Min);
        }
        for(register int i = 0; i < s; i++)
            scanf("%d", &s_age[i]);
        if(b <= s)
            printf("Case %d: 0\n", Case++);
        else {
            //sort(b_age, b_age+b, greater<int>());
            //sort(s_age, s_age+s, greater<int>());
            printf("Case %d: %d %d\n", Case++, b-s, Min);
        }
    }
    return 0;
}
