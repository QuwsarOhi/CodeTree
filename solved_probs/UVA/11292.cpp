//UVa
//11292 - Dragon of Loowater
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int k, d, knight[20010], dragon[20010], gold, n, m;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        for(register int i = 0; i < n; i++)
            scanf("%d", &dragon[i]);
        for(register int i = 0; i < m; i++)
            scanf("%d", &knight[i]);
        sort(dragon, dragon+n);
        sort(knight, knight+m);
        k = d = gold = 0;

        while(d < n && k < m) {
            while(dragon[d] > knight[k] && k < m) k++;
            if(k == m) break;
            gold += knight[k];
            //printf("taking %d'th knight : %d\n", k, knight[k]);
            d++, k++;
        }
        if(d < n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", gold);
    }
    return 0;
}
