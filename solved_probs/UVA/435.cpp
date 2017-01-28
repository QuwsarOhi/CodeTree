//UVa
//435 - Block Voting
#include<bits/stdc++.h>
using namespace std;

long a[40], averg, len, n, t, sum, indx[30];

void Subset_sum()
{
    for(long i = 0; i < len; i++) {
        sum = 0;
        for(long j = 0; j < n; j++)
            if(i & (1 << j))
                sum+=a[j];
        for(long j = 0; j < n; j++)
            if(i & (1 << j))
                if(sum >= averg && sum-a[j] < averg)
                    indx[j]++;
    }
}

int main()
{
    scanf("%ld", &t);
    while(t--) {
        scanf("%ld", &n);
        len = 1 << n;
        sum = 0;
        for(long i = 0; i < n; i++) {
            scanf("%ld", &a[i]);
            sum += a[i];
        }
        if(sum % 2 == 0) averg = sum / 2;
        else averg = (sum / 2) + 1;
        memset(indx, 0, sizeof(indx));
        Subset_sum();
        for(long i = 0; i < n; i++)
            printf("party %ld has power index %ld\n", i+1, indx[i]);
        printf("\n");
    }
    return 0;
}
