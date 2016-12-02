#include <stdio.h>

int main()

{
    int a[20], n, i, j, temp;

    printf("how many numbers?\n");
    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    for(i=0; i<n; i++)
        printf("%d\t", a[i]);


    return 0;

}

