//UVa
//11137 - Ingenuous Cubrency
#include<bits/stdc++.h>
#define lim 10000
using namespace std;

int coin[25];
long long memorise[10010];

int main()
{
    for(register int i = 1, j = 0; i <= 21; i++, j++)       //generating all coin values
        coin[j] = i*i*i;
    memset(memorise, 0, sizeof(memorise));
    memorise[0] = 1;
    for(register int coin_index = 0; coin_index < 21; coin_index++)
        for(register int i = coin[coin_index]; i <= lim; i++)
            memorise[i] += memorise[i-coin[coin_index]];
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%lld\n", memorise[n]);
    return 0;
}
