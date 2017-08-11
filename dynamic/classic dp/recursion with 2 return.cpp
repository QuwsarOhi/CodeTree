//UVa
//10465 - Homer Simpson
#include<bits/stdc++.h>
using namespace std;

int beer[10010], burger[10010];

int backtrack(int n, int m, int t, int *b)
{
    if(t - m < 0 && t - n < 0) {
        *b = t;
        return 0;
    }
    if(burger[t] != -1) {
        *b = beer[t];
        return burger[t];
    }
    int burger1 = 0, burger2 = 0, b1 = -1, b2 = -1;
    if(t-n >= 0)
        burger1 = backtrack(n, m, t-n, &b1) + 1;
    if(t-m >= 0)
        burger2 = backtrack(n, m, t-m, &b2) + 1;
    if(b1 == -1) {
        beer[t] = *b = b2;
        return burger[t] = burger2;
    }
    else if(b2 == -1) {
        beer[t] = *b = b1;
        return burger[t] = burger1;
    }
    else if(b1 != b2) {
        if(b1 < b2 && b1 != -1) {
            beer[t] = *b = b1;
            return burger[t] = burger1;
        }
        else {
            beer[t] = *b = b2;
            return burger[t] = burger2;
        }
    }
    else {
        if(burger1 > burger2) {
            beer[t] = *b = b1;
            return burger[t] = burger1;
        }
        else {
            beer[t] = *b = b2;
            return burger[t] = burger2;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, m, t, b;
    while(scanf("%d %d %d", &n, &m, &t) != EOF) {
        b = 0;
        memset(beer, -1, sizeof(beer));
        memset(burger, -1, sizeof(burger));
        int total = backtrack(n, m, t, &b);
        if(b == 0)
            printf("%d\n", total);
        else
            printf("%d %d\n", total, b);
    }
}
