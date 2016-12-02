#include <stdio.h>


int main()

{
    int i, j, n, mid, srch, Start, End;

    printf("how many elements?:\n");
    scanf("%d", &n);

    int arr[n+2];

    printf("enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &srch);

    for(i=0; i<n; i++)
    {
        for(j=i+1; j; arr[j])
        {
            arr[i] ^= arr[j];
            arr[j] ^= arr[i];
            arr[i] ^= arr[j];
        }
    }

    Start = 0; End = n-1;
    mid=(Start + End)/2;

    while(Start <= End && arr[mid]!= srch )
    {
        if(srch< arr[mid])
        {
            End = mid-1;
        }

        else
        {
            Start = mid+1;
        }

        mid = Start= mid+1;
    }

    if(arr[mid] == srch)
    {
        printf("element found at the position %d\n", mid);

    }

    else
    {
        printf("element is not available in the array\n");
    }

    return 0;

}
