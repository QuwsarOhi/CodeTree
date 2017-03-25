//1D Max Sum
//Algorithm : Jay Kadane
//Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    scanf("%d", &n);
    int A[n+1];
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    //Main part of the code

    int sum = 0, ans = 0;
    for(int i = 0; i < 9; i++) {
        sum += A[i];
        ans = max(sum, ans);                //always take the larger sum
        if(sum < 0)
            sum = 0;                        //if sum is negative, reset it (greedy)
    }
    printf("1D Max Sum : %d\n", ans);
    return 0;
}
