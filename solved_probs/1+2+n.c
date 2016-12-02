#include <stdio.h>
#include <math.h>

int main()
{
    int sum, i, n;
    sum=0;


    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("i = %d\n", i);
        sum=sum+pow(i,i);
        printf("sum = %d\n", sum);

    }

    printf("total sum = %d", sum);


    return 0;
}
