//UVa
//12346 - Water Gate Management
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int f[30], c[30], V, T, m, min_cost, n;
    bool found;
    scanf("%d", &n);
    for(register int i = 0; i < n; i++)
        scanf("%d %d", &f[i], &c[i]);
    scanf("%d", &m);
    for(register int t_case = 1; t_case <= m; t_case++) {
        scanf("%d %d", &V, &T);
        found = 0;
        min_cost = 1<<30;
        int limit = 1 << n;
        for(register int i = 1; i < limit; i++) {
            int total_flow = 0, cost = 0;
            for(register int j = 0; j < n; j++)
                if(i & (1 << j)) {
                    total_flow += f[j];
                    cost += c[j];
                }
            if(total_flow * T >= V) {
                found = 1;
                min_cost = min(cost, min_cost);
            }
        }
        if(found)
            printf("Case %d: %d\n", t_case, min_cost);
        else
            printf("Case %d: IMPOSSIBLE\n", t_case);
    }
    return 0;
}
