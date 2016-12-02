#include <stdio.h>

int main()

{
    int i, loc= -1, n, srch;

    printf("how many index?\n");
    scanf("%d", &n);

    int arr[n];

    printf("enter index numbers\n");

    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("which number to search?\n");
    scanf("%d", &srch);

    for(i=0; i<n; i++)
    {
        if(arr[i] == srch)
        {
            loc=i;
            break;
        }
    }

    if(loc == -1)
        printf("number not found!");
    if(loc != -1)
        printf("the number location is %d", loc+1);

    return 0;

}
