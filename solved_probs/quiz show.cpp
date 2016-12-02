#include <stdio.h>

int main()

{
    int i, a[3], maximum;

    maximum=0;

    for(i=0; i<3; i++)
        scanf("%d", &a[i]);

    for(i=0; i<3; i++)
        if(maximum<a[i])
        {
            maximum=a[i];
        }
    printf("%d", maximum);


    return 0;


}
