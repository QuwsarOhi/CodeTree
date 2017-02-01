//UVa
//10264 - The Most Potent Corner
#include<bits/stdc++.h>
using namespace std;

int weight[17000], potency[17000];

/*void bool_print(int n, int l)
{
    for(register int i = l; i >= 0; i--) {
        if(n & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}*/

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    register int dimention, total, sum, cnt, max_potency;
    while(scanf("%d", &dimention) != EOF) {
        total = 1 << dimention;
        for(register int i = 0; i < total; i++)
            scanf("%d", &weight[i]);
        for(register int i = 0; i < total; i++) {
            sum = 0;
            for(register int j = 0; j < dimention; j++)
                sum += weight[i ^ (1 << j)];
            potency[i] = sum;
        }
        max_potency = 0;
        for(int i = 0; i < total; i++)
            for(register int j = 0; j < dimention; j++)
                max_potency = max(max_potency, potency[i] + potency[i ^ (1 << j)]);
        printf("%d\n", max_potency);
    }
    return 0;
}
