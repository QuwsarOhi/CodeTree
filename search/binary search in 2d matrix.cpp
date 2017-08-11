//UVa
//12192 - Grapevine
#include<bits/stdc++.h>
using namespace std;

int a[510][510], N, M, query, mx, indx, L, U;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d %d", &N, &M) && (N || M)) {
        for(register int i = 0; i < N; i++)
            for(register int j = 0; j < M; j++)
                scanf("%d", &a[i][j]);
        scanf("%d", &query);
        while(query--) {
            scanf("%d %d", &L, &U);
            mx = 0;
            bool value_exists = 0;
            for(register int i = 0; i < N; i++) {
                int *p = lower_bound(a[i], a[i] + M, L);
                indx = p - a[i];
                for(int j = i, k = indx; j < N && k < M; j++, k++)
                    if(a[j][k] <= U)
                        mx = max(j - i + 1, mx);
            }
            if(mx == 0 && value_exists)
                mx = 1;
            printf("%d\n", mx);
        }
        printf("-\n");
    }
    return 0;
}
